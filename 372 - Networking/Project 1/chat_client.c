/*
	Riley Brandau
	CS 372
	Project 1
	Due 5/7/17
	Description: Sets up the client side of the client/server chat application.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

void getName(char *name);
int create_socket(struct addrinfo *res);
void connect_socket(int socketFD, struct addrinfo *res);
void chatSetup(int socketFD, char *clientName, char *serverName);
void performHandshake(int socketFD, char *user, char *server);

struct addrinfo *make_addrinfo(char *ip_addr, char *portNum)
{
	struct addrinfo hints, *res;
	int addrinfo_status;
	
	memset(&hints, 0, sizeof hints); //clearing all of hints' fields
	hints.ai_socktype = SOCK_STREAM; //setting socket type to TCP
	hints.ai_family = AF_INET;       //setting family to IPv4
	if((addrinfo_status = getaddrinfo(ip_addr, portNum, &hints, &res)) != 0)
	{
		fprintf(stderr, "ERROR: %s... Incorrect IP address and/or port number\n", gai_strerror(addrinfo_status));
		exit(1);
	}
	else
	{	
		return res;
	}
}


//main method
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Incorrect number of elements\n");
		exit(1);
	}
	
	char userName[10];
	char serverName[10];
	int socketFD = -5;
	struct addrinfo *res = make_addrinfo(argv[1], argv[2]);
	
	getName(userName); //get the user's name
	socketFD = create_socket(res); //create a socket
	connect_socket(socketFD, res); //connect socket
	performHandshake(socketFD, userName, serverName); //connect with server
	chatSetup(socketFD, userName, serverName); //initialize chat
	freeaddrinfo(res); //free up address information
}


//gets the user's name from the terminal
void getName(char *name)
{
	while(strlen(name) < 1 || strlen(name) > 10)
	{
		printf("Please enter your name (up to 10 characters): ");
		scanf("%s", name);
	}
}


//creates a socket based on address information
int create_socket(struct addrinfo *res)
{
	int socketFD;
	if((socketFD = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
	{
		fprintf(stderr, "ERROR: unable to create the socket\n");
		exit(1);
	}
	else
	{
		return socketFD;
	}
}


//connects the socket using the address provided in the address info
void connect_socket(int socketFD, struct addrinfo *res)
{
	int err_status = -5;
	if ((err_status = connect(socketFD, res->ai_addr, res->ai_addrlen)) == -1)
	{
		fprintf(stderr, "ERROR: unable to connect socket\n");
		exit(1);
	}
}


//initializes the chat functionality between the client and server sockets
//the client starts the communication between the client and the server
void chatSetup(int socketFD, char *clientName, char *serverName)
{
	int B_sent = 0; //variable for tracking number of Bytes sent
	int B_recv = -5; //variable for error detection
	char input[503]; //input buffer
	char output[501]; //output buffer
	memset(input, 0, sizeof(input)); //clear input buffer
	memset(output, 0, sizeof(output)); //clear output buffer
	fgets(input, 500, stdin); //clear standard input of any \n
	
	while(1)
	{
		printf("%s> ", clientName); //display user's chat prompt
		
		fgets(input, 502, stdin); //get messages from the user
		if (strcmp(input, "\\quit\n") == 0) //if the user entered \quit, break and close the connection
		{
			printf("Goodbye, %s\n", clientName);
			break;
		}
		B_sent = send(socketFD, input, strlen(input), 0); //send the user's message
		if(B_sent == -1)
		{
			fprintf(stderr, "ERROR: unable to send data\n");
			exit(1);
		}
		
		B_recv = recv(socketFD, output, 500, 0); //retrieve the message 
		if(B_recv == -1) //there was an error receiving the message
		{
			fprintf(stderr, "ERROR: unable to receive message\n");
			exit(1);
		}
		else if (B_recv == 0) //the server closed the connection
		{
			printf("Server has terminated connection\n");
			break;
		}
		else //Success! print out the received message
		{
			printf("%s> %s\n", serverName, output);
		}
		memset(input, 0, sizeof(input)); //reset input buffer for next message
		memset(output, 0, sizeof(output)); //reset output buffer for next message
	}
	close(socketFD);
	printf("Connection has been closed.\n");
}


//sends client's information to the server, and the server's information to the client
void performHandshake(int socketFD, char *user, char *server)
{
	int sendInfo = -5;
	int recvInfo = -5;
	sendInfo = send(socketFD, user, strlen(user), 0); //send client info to the server
	if(sendInfo == -5)
	{
		fprintf(stderr, "ERROR: unable to send user info\n");
		exit(1);
	}
	recvInfo = recv(socketFD, server, 10, 0); //receives server info
	if(recvInfo == -5)
	{
		fprintf(stderr, "ERROR: unable to receive server info\n");
		exit(1);
	}
}

	
