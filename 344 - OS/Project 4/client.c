/*
 * Riley Brandau
 * CS 344 - Project 4 - client.c
 * Due: 3/19/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>


#ifdef ENCRYPT
#define SERVERTYPE 'e'
#elif DECRYPT
#define SERVERTYPE 'd'
#endif


#define IP_PROTO 0


void readMsg(char *portNum, char *msgFile, char *keyFile);
void sendMsg(char *portNum, char *msg_buf, char *key_buf, size_t msg_length);

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        fprintf(stderr, "ERROR: wrong number of arguments!\n");
        exit(EXIT_FAILURE);
    }
    readMsg(argv[3], argv[1], argv[2]);
    return 0;
}

void readMsg(char *portNum, char *msgFile, char *keyFile)
{
    int error = -5;
    struct stat buffer;
	int keyFD = -5;
	int msgFD = -5;
	size_t key_length;
	size_t msg_length;
	
    error = stat(msgFile, &buffer);                                                                //get message file status
    if (error == -1) 
    {
        perror("ERROR: Wrong message file status\n");
        exit(EXIT_FAILURE);
    }

    msg_length = buffer.st_size - 1;                                                               //remove newline from msg length

    error = stat(keyFile, &buffer);                                                                //get key file status
    if (error == -1) 
    {
        perror("ERROR: Wrong key file status\n");
        exit(EXIT_FAILURE);
    }

    key_length = buffer.st_size - 1;                                                               //remove the '\n' from the key length

    if (key_length < msg_length)                                                                   //make sure that the key is at least as long as the message
    {
        fprintf(stderr, "ERROR: Key and message are not the same length!\n");
        exit(EXIT_FAILURE);
    }

    char *msg_buf = malloc(msg_length);                                                            //create space for the key and message
    char *key_buf = malloc(msg_length);

    keyFD = open(keyFile, O_RDONLY);                                                               //open the key file
    if (keyFD == -1) 
    {
        perror("ERROR: unable to open key file\n");
        exit(EXIT_FAILURE);
    }

    msgFD = open(msgFile, O_RDONLY);                                                               //open the message file
    if (msgFD == -1) 
    {
        perror("ERROR: unable to open message file\n");
        exit(EXIT_FAILURE);
    }

    error = read(msgFD, msg_buf, msg_length);                                                      //read the message into its buffer
    if (error == -1) 
    {
        perror("ERROR: unable to read message file\n");
        exit(EXIT_FAILURE);
    }

    error = read(keyFD, key_buf, msg_length);                                                      //read the key into its buffer
    if (error == -1) 
    {
        perror("ERROR: unable to read key file\n");
        exit(EXIT_FAILURE);
    }

    close(keyFD);                                                                                  //close files
    close(msgFD);

    size_t i = -5;
    for (i = 0; i < msg_length; i++) 
    {
        if (!(msg_buf[i] == ' ' || (msg_buf[i] >= 'A' && msg_buf[i] <= 'Z')))                      //if the message character is not A-Z or a space
        {
            fprintf(stderr, "ERROR: Invalid message character found: %c.\n", msg_buf[i]);
            printf("%s", msg_buf);
            exit(EXIT_FAILURE);
        }

        if (!(key_buf[i] == ' ' || (key_buf[i] >= 'A' && key_buf[i] <= 'Z')))                      //if the key character is not A-Z or a space
        {
            fprintf(stderr, "ERROR: Invalid key character found: %c.\n", key_buf[i]);
            exit(EXIT_FAILURE);
        }
    }

    sendMsg(portNum, msg_buf, key_buf, msg_length);                                                //send the message and key
    free(msg_buf);                                                                                 //free the message and key buffers
    free(key_buf);
}

void sendMsg(char *portNum, char *msg_buf, char *key_buf, size_t msg_length)
{
    int p_num = (int)strtol(portNum, NULL, 10);
    int socketFD = -5;
    int error = -5;
    struct sockaddr_in serv_addr;
    char c_type = SERVERTYPE;
    char s_type = 2;

    socketFD = socket(AF_INET, SOCK_STREAM, IP_PROTO);                                             //open socket
    if (socketFD < 0) 
    {
        perror("ERROR: unable to open socket\n");
        exit(EXIT_FAILURE);
    }

    inet_pton(AF_INET, portNum, &(serv_addr.sin_addr));                                            //convert from text to binary                
    serv_addr.sin_family = AF_INET;                                                                //set the TCP/IP protocol
    serv_addr.sin_port = htons(p_num);                                                             //convert to network byte order

    error = connect(socketFD, (struct sockaddr *)&serv_addr, sizeof(serv_addr));                   //connect to the socket
    if (error < 0) 
    {
        perror("ERROR: unable to connect to socket\n");
        exit(EXIT_FAILURE);
    }

    error = write(socketFD, &c_type, sizeof(char));                                                //send client type to socket
    if (error < 0) 
    {
        perror("ERROR: unable to write client type to socket\n");
        exit(EXIT_FAILURE);
    }

    error = read(socketFD, &s_type, sizeof(char));                                                 //get the server type
    if (error < 0) 
    {
        perror("ERROR: unable to read server type from socket");
        exit(EXIT_FAILURE);
    }

    if (s_type != c_type)                                                                          //verify that client and server are same type
    {
        fprintf(stderr, "ERROR: Incompatible server and client types\n");
        shutdown(socketFD, 2);
        close(socketFD);
        exit(EXIT_FAILURE);
    }

    error = write(socketFD, &msg_length, sizeof(size_t));                                          //send the length of the message
    if (error < 0) 
    {
        perror("ERROR: unable to write msg_length to the socket\n");
        exit(EXIT_FAILURE);
    }

    error = write(socketFD, msg_buf, msg_length);                                                  //send the message
    if (error < 0) 
    {
        perror("ERROR: unable to write message to the socket\n");
        exit(EXIT_FAILURE);
    }

    error = write(socketFD, key_buf, msg_length);                                                  //send the key
    if (error < 0) 
    {
        perror("ERROR: unable to write key to the socket\n");
        exit(EXIT_FAILURE);
    }

    error = read(socketFD, msg_buf, msg_length);                                                   //get the response (encrypted/decrypted)
    if (error < 0) 
    {
        perror("ERROR: unable to read response from the socket\n");  
        exit(EXIT_FAILURE);
    }
    write(STDOUT_FILENO, msg_buf, msg_length);                                                     //write the message
    write(STDOUT_FILENO, "\n", 1);
    close(socketFD);
}
