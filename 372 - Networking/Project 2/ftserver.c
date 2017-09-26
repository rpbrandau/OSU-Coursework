/*
Riley Brandau
CS 372 - Project 2
Description: This is the server side portion of the project.
Sources: https://tinyurl.com/yadopf8x (stack overflow - checking files)
OSU class discussion pages
https://beej.us/guide/bgnet/ (general reference)
https://tinyurl.com/yd6jhv54(stack overflow - sending files) 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h> 
#include <arpa/inet.h> 

#include <dirent.h> 
#include <unistd.h> 
#include <fcntl.h> 


//Struct that has a pointer to linked list inside of address info
struct addrinfo *makeAddrInfo(char *portNum)
{
	int err;
	struct addrinfo hints;
	struct addrinfo *res;
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if((err = getaddrinfo(NULL, portNum, &hints, &res)) != 0)
	{
		fprintf(stderr, "GETADDRINFO ERROR: %s: Incorrect Port/IP\n", gai_strerror(err));
		exit(1);
	}
	return res;
}


//Struct that has a pointer to an IP address and port number
struct addrinfo *makeAddrInfoIP(char *ipAddr, char *portNum)
{
	int err;
	struct addrinfo hints;
	struct addrinfo *res;
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	if((err = getaddrinfo(ipAddr, portNum, &hints, &res)) != 0)
	{
		fprintf(stderr, "GETADDRINFO ERROR: %s: Incorrect Port/IP\n", gai_strerror(err));
		exit(1);
	}
	
	return res;
}


//Prototypes
int makeSocket(struct addrinfo *);
void connectSocket(int, struct addrinfo *);
void bindSocket(int, struct addrinfo *);
void listenToSocket(int);
char **makeFileArray(int);
void deleteFileArray(char **, int);
int getServerFileList(char **);
int validateFile(char **, int, char *);
void sendFile(char *, char *, char *);
void sendFileList(char *, char *, char **, int);
void handleClientRequest(int);
void waitForClientConnection(int);


//Main Method
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Invalid number of arguments\nFormat: a.out <portNum>\n");
		exit(1);
	}
	
	printf("Server ready for connections on port %s\n", argv[1]);
	struct addrinfo *res = makeAddrInfo(argv[1]);
	int socketFD = -5;
	socketFD = makeSocket(res); //make the socket
	bindSocket(socketFD, res);  //bind the socket
	listenToSocket(socketFD);   //start listening for incoming data
	waitForClientConnection(socketFD); //wait for connections/requests
	freeaddrinfo(res);          //clean up
}


//Method for creating a socket connection
int makeSocket(struct addrinfo *res)
{
	int socketFD;
	if ((socketFD = socket((struct addrinfo *)(res)->ai_family, res->ai_socktype, res->ai_protocol)) == -1) //if unable to create the socket
	{
		fprintf(stderr, "ERROR: unable to MAKE socket\n");
		exit(1);
	}
	return socketFD;
}


//Method for connecting socket to specified address
void connectSocket(int socketFD, struct addrinfo *res)
{
	int err;
	
	if ((err = connect(socketFD, res->ai_addr, res->ai_addrlen)) == -1) //if the connection fails...
	{
		fprintf(stderr, "ERROR: unable to CONNECT socket\n");
		exit(1);
	}
}


//Method for binding the socket to a port
void bindSocket(int socketFD, struct addrinfo *res)
{
	if (bind(socketFD, res->ai_addr, res->ai_addrlen) == -1) //if the bind fails 
	{
		close(socketFD);
		fprintf(stderr, "ERROR: unable to BIND socket\n");
		exit(1);
	}
}


//Method for keeping a socket open for listening
void listenToSocket(int socketFD)
{
	if(listen(socketFD, 5) == -1) //close if an error occurs
	{
		close(socketFD);
		fprintf(stderr, "ERROR: unable to listen to socket\n");
		exit(1);
	}
}


//Method for making an array of strings for holding directory file names
char **makeFileArray(int arrSize)
{
	char **fileArray = malloc(arrSize*sizeof(char *));
	int i = -5;
	
	for(i = 0; i < arrSize; i++)
	{
		fileArray[i] = malloc(100*sizeof(char));
		memset(fileArray[i],0,sizeof(fileArray[i]));
	}
	return fileArray;
}


//Method for cleaning up the array of file names
void deleteFileArray(char **fileArray, int arrSize)
{
	int i = -5;
	
	for (i = 0; i < arrSize; i++)
	{
		free(fileArray[i]);
	}
	free(fileArray);
}


//Method for determining what files are in the server's directory (SO helped)
int getServerFileList(char **fileArray)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	int i = 0;
	
	if (d)
	{
		while ((dir = readdir(d)) != NULL) //while there are files in the directory
		{
			if (dir->d_type == DT_REG)     //checking to see if the files are actual files (not links, etc)
			{
				strcpy(fileArray[i], dir->d_name); //copy the file names into the array
				i++;
			}
		}
		closedir(d);
	}
	return i;
}


//Method for checking if requested file is in server directory
int validateFile(char **fileArray, int fileCount, char *fileName)
{
	int fileIsValid = 0;
	int i = -5;
	for (i = 0; i < fileCount; i++)
	{
		if(strcmp(fileArray[i], fileName) == 0) //loop through array to see if filename is in there
		{
			fileIsValid = 1; //if it is, mark it as valid and return
		}
	}
	return fileIsValid;
}


//method for sending a file to the client
void sendFile(char *ipAddr, char *portNum, char *fileName)
{
	sleep(2); //give time to connect to the socket - SO comment mentioned this is kinda hacky...
	struct addrinfo *res = makeAddrInfoIP(ipAddr, portNum);
	int fileInfo = -5;
	fileInfo = makeSocket(res);
	connectSocket(fileInfo, res);
	char fileBuffer[1000]; //buffer for file contents
	memset(fileBuffer, 0, sizeof(fileBuffer)); //clear the buffer for writing
	int fileDescriptor = -5;
	fileDescriptor = open(fileName, O_RDONLY); //open the file for reading
	
	while (1) 
	{
		int bytesIn = -5;
		bytesIn = read(fileDescriptor, fileBuffer, sizeof(fileBuffer)-1); //keeping track of how many bytes were read
		
		if (bytesIn == 0) //If we're finished reading the file, break
		{
			break;
		}

		if (bytesIn < 0) //If we somehow have negative bytes in somehow, something bad happened
		{
			fprintf(stderr, "ERROR: unable to read file\n");
			return;
		}

		void *fBufferPtr = fileBuffer; //this pointer keeps track of where in the buffer we are
		
		while (bytesIn > 0) //loop while there are still bytes left to be written
		{
			int bytesOut = - 5;
			bytesOut = send(fileInfo, fBufferPtr, sizeof(fileBuffer),0); //keep track of how many bytes were written
			
			if (bytesOut < 0) //if we have negative bytes out somehow, something bad happened
			{
				fprintf(stderr, "ERROR: unable to write to socket\n");
				return;
			}
			
			bytesIn -= bytesOut; //update to see how many bytes are left to write
			fBufferPtr += bytesOut; //update the pointer location
		}
		
		memset(fileBuffer, 0, sizeof(fileBuffer)); //clear the file buffer for next loop
	}
	
	memset(fileBuffer, 0, sizeof(fileBuffer)); //clear the file buffer for final send
	strcpy(fileBuffer, "__complete__"); //put in our signal to the client that there is no more information to send
	send(fileInfo, fileBuffer, sizeof(fileBuffer),0); //send the terminating signal to the client
	close(fileInfo); //close the socket
	freeaddrinfo(res); //clean up the address info
}

//Method for sending the list of file names in the Server's directory
void sendFileList(char *ipAddr, char *portNum, char **fileArray, int fileCount)
{
	int i = -5;
	sleep(2); //give time to connect to the socket - SO comment mentioned this is kinda hacky...
	struct addrinfo *res = makeAddrInfoIP(ipAddr, portNum); //store address info
	int fileInfo = -5;
	fileInfo = makeSocket(res); //make a new socket
	connectSocket(fileInfo, res); //connect to the new socket

	for (i = 0; i < fileCount; i++)
	{
		send(fileInfo, fileArray[i], 100,0); //loop and send the file names in the array
	}
	
	char *finMsg = "Complete."; //message to signal the client that the server is finished sending info
	send(fileInfo, finMsg, strlen(finMsg),0); //send the finished message
	close(fileInfo); //close the socket
	freeaddrinfo(res); //clean up the address info
}


void handleClientRequest(int newFD)
{
	char *posMsg = "accepted"; //messages for client commands
	char *negMsg = "rejected";
	char portBuffer[100]; //buffer for storing port number information
	memset(portBuffer, 0, sizeof(portBuffer)); //clear out port buffer
	recv(newFD, portBuffer, sizeof(portBuffer)-1, 0); //get the port info from client
	send(newFD, posMsg, strlen(posMsg),0); //acknowledgement
	char userCommandBuffer[100]; //buffer for storing the user's command (-l or -g)
	memset(userCommandBuffer, 0, sizeof(userCommandBuffer)); //clear the buffer
	recv(newFD, userCommandBuffer, sizeof(userCommandBuffer)-1, 0); //get the command
	send(newFD, posMsg, strlen(posMsg),0); //acknowledgement
	char ipAddrBuffer[100]; //buffer for storing client's IP address
	memset(ipAddrBuffer,0,sizeof(ipAddrBuffer)); //clear the buffer
	recv(newFD, ipAddrBuffer, sizeof(ipAddrBuffer)-1,0); //get the IP address
	printf("Connection from %s\n", ipAddrBuffer); //display connection
	if(strcmp(userCommandBuffer,"l") == 0) //check to see if the command was "-l"
	{
		char **fileArray = makeFileArray(100); //create an array to store file names
		int fileCount = -5;
		send(newFD, posMsg, strlen(posMsg),0); //acknowledge the command
		printf("Server file list requested on port#: %s\n", portBuffer); //display what was requested
		printf("Sending server file list to %s on port %s\n", ipAddrBuffer, portBuffer); //display where requested data will go
		fileCount = getServerFileList(fileArray); //get number of files
		sendFileList(ipAddrBuffer, portBuffer, fileArray, fileCount); //send the list of files to client
		deleteFileArray(fileArray,100); //clean up file array
	}
	else if(strcmp(userCommandBuffer, "g") == 0) //check to see if the command was "-g"
	{
		char fileNameBuffer[100]; //buffer to store file name requested by client
		memset(fileNameBuffer, 0, sizeof(fileNameBuffer)); //clear the buffer
		send(newFD, posMsg, strlen(posMsg),0); //acknowledge the command
		recv(newFD, fileNameBuffer, sizeof(fileNameBuffer)-1,0); //get the file name from the client
		printf("File: %s\nRequested on port #: %s\n", fileNameBuffer, portBuffer); //display what was requested
		char **fileArray = makeFileArray(100); //create an array to store file names
		int fileCount = getServerFileList(fileArray); //get number of files
		int fileIsValid = validateFile(fileArray, fileCount, fileNameBuffer); //check to see if requested file is in server's folder
		if(fileIsValid) //the file was found in the server's folder
		{
			char *validFile = "File valid"; //message to notify client
			printf("File is valid\nSending %s to client\n", fileNameBuffer); //display that the server found the file
			send(newFD, validFile, strlen(validFile),0); //tell client the file was found by the server
			char updatedFileName[100]; //buffer to store file name that will have location info
			memset(updatedFileName,0,sizeof(updatedFileName)); //clear the buffer
			strcpy(updatedFileName, "./"); 
			char *end = updatedFileName + strlen(updatedFileName); //building file name
			end += sprintf(end, "%s", fileNameBuffer); //finished building file name
			sendFile(ipAddrBuffer, portBuffer, updatedFileName); //send the requested file to the client
		}
		else //the server was not able to find the requested file
		{
			char *errMsg = "ERROR: File not found";
			printf("ERROR: File not found, sending error message to client\n");
			send(newFD, errMsg, 100, 0); //send the error message to the client
		}
		deleteFileArray(fileArray, 100); //Clean up file array
	}
	else //the client sent something other than -l or -g
	{
		send(newFD, negMsg, strlen(negMsg), 0); //notify client their command was rejected
		printf("ERROR: Command not recognized\n");
	}
	printf("Waiting for incoming connections...\n"); //Server is ready for a new connection
}


//Method that waits for clients to connect
void waitForClientConnection(int socketFD)
{
	int newFD;
	struct sockaddr_storage clientAddr; //struct to hold client address info
    socklen_t addr_size;

	while(1) //keep the server on and listening for incomming connections until a ctrl-c is issued
	{
		addr_size = sizeof(clientAddr);
		newFD = accept(socketFD, (struct addrinfo *)&clientAddr, &addr_size); //accept a connection from a client
		if(newFD == -1) //even if an error occurs while connecting, keep running
		{
			continue;
		}
		handleClientRequest(newFD); //handle the client's requested
		close(newFD); //close the connection
	}
}
