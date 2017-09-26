/*
 * Riley Brandau
 * CS 344 - Project 4 - server.c
 * Due 3/19/17
 * Got some help from www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/wait.h>


#define IP_PROTO 0

#ifdef ENCRYPT
#define SERVERTYPE 'e'
#define MOD27_CRYPT(a, b) (a) = (int)((int)(a) + (int)(b));                                        //encryption and decryption methods
#elif DECRYPT
#define SERVERTYPE 'd'
#define MOD27_CRYPT(a, b) (a) = (int)((int)(a) - (int)(b));
#endif

void setup(int portnum);
void otp(size_t msg_length, char *key_buf, char*msg_buf);
void process_loop(int socketFD);
void term_child(int signo);
void disconnect(int _);
void cleanup(int c_socketFD, char *key_buf, char *msg_buf);

int main (int argc, char *argv[]) 
{
    int portnum = -5;
   
    signal(SIGINT, disconnect);
    signal(SIGCHLD, term_child);
    
    if (argc != 2) 
    {
        fprintf(stderr, "ERROR: No port!\n");
        exit(EXIT_FAILURE);
    }
	
    portnum = (int)strtol(argv[1], NULL, 10);
    setup(portnum);
}

//Interrupt traps that have the signature int func(int)
//Ignore the signal number.
void disconnect(int _) 
{
    int child = -5;
    pid_t pid;
    pid = waitpid(0, &child, 0);
	
    while (pid != -1) {}                                                                           //Wait for children
	
    if (errno == ECHILD) 
    {
        exit(EXIT_SUCCESS);
    } 
    else 
    {
        perror("ERROR: Reaping child processes\n");
        exit(EXIT_FAILURE);
    }
}


//Interrupt traps that have the signature 'int func(int)'
//Ignore the signal number.
//Reap the child processes as they die
void term_child(int signo) 
{
    int child = -5;
    pid_t pid;
    pid = waitpid(0, &child, 0);
    if (pid == -1) 
    {
        perror("ERROR: Reaping child process after SIGCHLD.\n");
        exit(EXIT_FAILURE);
    }
}


void setup(int portnum) 
{
    int socketFD = -5; 
    int error = -5;
    struct sockaddr_in serv_addr;

    socketFD = socket(AF_INET, SOCK_STREAM, IP_PROTO);                                             //Open the socket via TCP/IP
    if (socketFD < 0) 
    {
        perror("ERROR: Unable to open socket!\n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;                                                                //set address family
    serv_addr.sin_port = htons(portnum);                                                           //convert to network byte order
    serv_addr.sin_addr.s_addr = INADDR_ANY;                                                        //local host
   
    error = bind(socketFD, (struct sockaddr *) &serv_addr, sizeof(serv_addr));                     //bind the socket
   
    if (error < 0) 
    {
        perror("ERROR: Failed to bind to the socket\n");
        exit(EXIT_FAILURE);
    }

    error = listen(socketFD, 5);                                                                   //most systems can only have a max of 5 for backlog queue
   
    if (error < 0) 
    {
        perror("ERROR: Failed to listen on the socket\n");
        exit(EXIT_FAILURE);
    }
    
    process_loop(socketFD);                                                                        //proceed to processing msg/key
}


void process_loop(int socketFD) 
{
    int new_socketFD = -5;
    int error = -5;
    char c_type = 1;
    char s_type = SERVERTYPE;
    char *msg_buf;
    char *key_buf;
	size_t msg_length;
    
	struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    while (1) 
    {
        new_socketFD = accept(socketFD, (struct sockaddr *) &cli_addr, &clilen);                   //accept new client connections
       
	if (new_socketFD < 0)
	{
            perror("ERROR: unable to accept connection\n");
        }
		
        pid_t pid = fork();                                                                        //fork off processes
       
	if (pid == 0)                                                                              //child process
	{
            error = read(new_socketFD, &c_type, sizeof(char));                                     //get the client type (encryption/decryption)
           
            if (error < 0) 
	    {
                perror("ERROR: unable to read from socket");
                cleanup(new_socketFD, NULL, NULL);
                exit(EXIT_FAILURE);
            }

            error = write(new_socketFD, &s_type, sizeof(char));                                    //write the server type (encryption/decryption)
            
	    if (error < 0) 
	    {
                perror("ERROR: unable to write program type to socket");
                cleanup(new_socketFD, NULL, NULL);
                exit(EXIT_FAILURE);
            }

            if (c_type != s_type)                                                                  //check to see that client and server are same type
	    {
                fprintf(stderr, "ERROR: incompatible connection types\n");
                shutdown(new_socketFD, 2);
                close(new_socketFD);
                exit(EXIT_FAILURE);
            }

            error = read(new_socketFD, &msg_length, sizeof(size_t));                               //get the message length
			
            if (error < 0) 
	    {
                perror("ERROR: unable to read from socket\n");
                cleanup(new_socketFD, NULL, NULL);
                exit(EXIT_FAILURE);
            }

            msg_buf = malloc(msg_length);                                                          //make space for the message and key
            key_buf = malloc(msg_length);

            error = read(new_socketFD, msg_buf, msg_length);                                       //read in the message
            
	    if (error < 0) 
            {
                perror("ERROR: unable to read from socket\n");
                cleanup(new_socketFD, key_buf, msg_buf);
                exit(EXIT_FAILURE);
            }

            error = read(new_socketFD, key_buf, msg_length);                                       //read in the key
           
	    if (error < 0)
	    {
                perror("ERROR: unable to read from socket\n");
                cleanup(new_socketFD, key_buf, msg_buf);
                exit(EXIT_FAILURE);
            }

            otp(msg_length, key_buf, msg_buf);                                                     //send the message and key to be encrypted/decrypted

            error = write(new_socketFD, msg_buf, msg_length);                                      //write the response
            
	    if (error < 0) 
	    {
                perror("ERROR: unable to write to socket\n");
            }
            
            cleanup(new_socketFD, key_buf, msg_buf);                                               //clean up
            exit(EXIT_SUCCESS);
        } 
	else 
	{
            continue;
        }
    }
}

//performs encryption/decryption
void otp(size_t msg_length, char *key_buf, char *msg_buf) 
{
    size_t i = -5;
	
    for (i = 0; i < msg_length; i++)                                                               //go through message and change spaces into '[' since it's 'Z'+1
    {
        if (msg_buf[i] == ' ')
	{
	    msg_buf[i] = '[';
	}
	if (key_buf[i] == ' ')
	{
	    key_buf[i] = '[';
	}
        msg_buf[i] -= 'A';                                                                         //subtract A from msg
        key_buf[i] -= 'A';                                                                         //subtract A from key
    }

    for (i = 0; i < msg_length; i++)                                                               //loop through the message and perform the modulo27 encryption
    {
        MOD27_CRYPT(msg_buf[i], key_buf[i])
        if (msg_buf[i] < 0) 
	{
            msg_buf[i] += 27;
        } 
	else 
	{
            msg_buf[i] %= 27;
        }
    }

    for (i = 0; i < msg_length; i++)                                                                //undo transformation to arrive at original alphabet sequence
    {
        msg_buf[i] += 'A';
        key_buf[i] += 'A';
        
        if (msg_buf[i] == '[') 
	{
            msg_buf[i] = ' ';
        }
        if (key_buf[i] == '[') 
	{
            key_buf[i] = ' ';
        }
    }
}

//Handles cleanup tasks
void cleanup(int c_socketFD, char *key_buf, char *msg_buf) 
{
    int error = -5;
	
    if (msg_buf != NULL)                                                                           //as long as the buffers aren't NULL, free them
    {
        free(msg_buf);
    }
    if (key_buf != NULL) 
    {
        free(key_buf);
    }

    error = shutdown(c_socketFD, 2);                                                               //shutdown the client's socket connections
	
    if (error == -1) 
    {
        perror("ERROR: Unable to shutdown the client socket file descriptor\n");
    }
    close(c_socketFD);                                                                             //close the client's file descriptors
}
