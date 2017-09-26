#!/usr/bin/python

"""
Riley Brandau
CS 372
Project 1 - Chat client/server
Due 5/7/17
Description: Server part of the client/server chat application
"""


import sys
from socket import *


#sends and receives usernames of client and server
def makeHandshake(connection_socket, serverName):
	clientName = connection_socket.recv(1024) #get the client's name
	connection_socket.send(serverName) #send the client the server's name
	return clientName

	
#Creates the chat session with the client; the client sends the first message	
def chatServ(connection_socket, clientName, serverName):
	sendMsg = ""
	while 1:
		recvMsg = connection_socket.recv(501)[0:-1] #get the message from the client
		if recvMsg == "": #if no message is received, break the loop and close the connection
			print "Connection has been terminated or no connection has been made"
			print "Waiting for a client to connect..."
			break
		print "{}> {}".format(clientName, recvMsg) #print out the received message
		sendMsg =""
		while len(sendMsg) == 0 or len(sendMsg) > 500:
			sendMsg = raw_input("{}> ".format(clientName)) #send input from server side to client
		if sendMsg == "\quit": #if the message is \quit, quit the program
			print "Connection has been terminated."
			print "Waiting for a client to connect..."
			break
		connection_socket.send(sendMsg)

		
if __name__ == "__main__":
	if len(sys.argv) != 2: #make sure we have the correct number of arguments
		print "ERROR: No port number specified."
		exit(1)
	portNum = sys.argv[1] #assign the port number provided to a variable
	tcpServSocket = socket(AF_INET, SOCK_STREAM) #create the TCP socket
	tcpServSocket.bind(('', int(portNum))) #bind the socket to the port number
	tcpServSocket.listen(1) #make the socket available to listen for incoming messages
	clientName = "" 
	while len(clientName) == 0 or len(clientName) > 10: #get the name from the client
		clientName = raw_input("Please enter your name (up to 10 characters): ")
		print "Awaiting incoming messages..."
	while 1:
		connection_socket, address = tcpServSocket.accept() #make a connection
		print "Connection request accepted from {}".format(address) #display connection info
		chatServ(connection_socket, makeHandshake(connection_socket, clientName), clientName) #handshake with the connection, and begin chatting
		connection_socket.close() #close the connection when finished chatting
