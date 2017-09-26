#!/bin/python

#Riley Brandau
#CS372 - Project 2
#Client portion of project
#Sources: https://tinyurl.com/yctrcagl (OSU class discussion)
#via OSU discussion (stack overflow): https://tinyurl.com/ydgneh84
#https://docs.python.org/3.4/howto/sockets.html

from socket import *
import sys



#Method for making a socket
def makeSocket():
	if sys.argv[3] == "-l": #depending on the command, there will be 5-6 args
		portArg = 4         #if -l, the port will be arg[4]
	elif sys.argv[3] == "-g":
		portArg = 5         #if -g, the port will be arg[5]

	servPort = int(sys.argv[portArg]) #get server port number
 	servSocket = socket(AF_INET, SOCK_STREAM) #get make server socket
	servSocket.bind(('', servPort)) #bind the server socket
	servSocket.listen(1) #listen to server socket
	info, address = servSocket.accept() #accept server socket connection
	
	return info #pass socket that will have information


#Method for getting file names in the server directory
def getFileNames(info):
	fileName = info.recv(100) #get file name from received list
	
	while fileName != "Complete.": #server message that indicates list is finished
		print fileName #display the file name
		fileName = info.recv(100) #get the next file name


#Method for retrieving a file from the server
def getFileData(info):
	file = open(sys.argv[4],"w") #create a file to write to
	infoBuf = info.recv(1000) #create a buffer for the file data
	
	while "__complete__" not in infoBuf: #server message that indicates transfer is complete
		file.write(infoBuf) #write the info to the file
		infoBuf = info.recv(1000) #read more info into the buffer


#Method for sending and receiving information 
def sendRecvData(clientSocket):
	if sys.argv[3] == "-l":
		print "Getting list of files..."
		portNum = 4
	elif sys.argv[3] == "-g":
		print "{} requested".format(sys.argv[4])
		portNum = 5
	
	clientSocket.send(sys.argv[portNum]) #send server info port number
	clientSocket.recv(1024)

	if sys.argv[3] == "-l":
		clientSocket.send("l") #send the list command to server
	else:
		clientSocket.send("g") #send the get command to server

	clientSocket.recv(1024)
	clientSocket.send(currentIP()) #send the client's ip address to the server
	response = clientSocket.recv(1024)
	
	if response == "rejected": #check server response
		print "ERROR: Invalid command"
 		exit(1)
	
	if sys.argv[3] == "-g":
		clientSocket.send(sys.argv[4])
		response = clientSocket.recv(1024)
        	if response != "File valid": #check to see if the requested file is valid/present	
 			print "Server was unable to find file..."
			return
    
	info = makeSocket() #set up the socket to receive information
	
	if sys.argv[3] == "-l":
		getFileNames(info) #display the list of server files
	
	elif(sys.argv[3] == "-g"): 
		getFileData(info) #get the file from the server
	
	info.close() #close the socket


#Method for determining correct IP address (discussions/so helped)
def currentIP():
	address = socket(AF_INET, SOCK_DGRAM)
	address.connect(("8.8.8.8", 80)) #I believe this goes through google's DNS
	ip = address.getsockname()[0] #get the socket name of the address
	address.close() #close the socket
	return ip #return the ip address


def connectServer():
	servName = sys.argv[1]+".engr.oregonstate.edu" #add the rest of the address to whichever flip server
	servPort = int(sys.argv[2]) #get the port number and convert to an int
	clientSocket = socket(AF_INET,SOCK_STREAM) #open a socket
	clientSocket.connect((servName, servPort)) #connect to the server port
	
	return clientSocket


#method for validating passed arguments
def argValidation():
	if len(sys.argv) < 5 or len(sys.argv) > 6: #number of passed arguments will be 5 or 6, depending on command
		print "Number of arguments must be 5 or 6"
		print "To list files: ftclient.py <serverName> <serverPort> <-l> <clientPort>"
		print "To get files: ftclient.py <serverName> <serverPort> <-g> <fileName> <clientPort>" 
		exit(1)
    
	elif (sys.argv[1] != "flip1" and sys.argv[1] != "flip2" and sys.argv[1] != "flip3"): #arg[1] needs to be flip1, 2, or 3
		print "Server name not recognized..."
		print "Acceptable server names: <flip1> <flip2> <flip3>"
		exit(1)
    
	elif (int(sys.argv[2]) < 1024 or int(sys.argv[2]) > 65535): #port number will be arg[2] and must be between 1024 and 65535
		print "Server port outside of acceptable range"
		print "Must be between 1024 and 65535"
		exit(1)

	elif (sys.argv[3] != "-l" and sys.argv[3] != "-g"): #arg[3] will be a user command: either -l or -get
		print "Invalid command"
		print "Valid commands: <-l> <-g>"
		exit(1)

	elif (sys.argv[3] == "-l" and (int(sys.argv[4]) < 1024 or int(sys.argv[4]) > 65535 or int(sys.argv[4]) == int(sys.argv[2]))): #arg[4] will be client port if -l was issued, so need to check port range
		print "Client port outside of acceptable range"
		print "Must be between 1024 and 65535, and != server port"
 		exit(1)

	elif (sys.argv[3] == "-g" and (int(sys.argv[5]) < 1024 or int(sys.argv[5]) > 65535 or int(sys.argv[5]) == int(sys.argv[2]))): #arg[5] will be client port if -g was issued, so need to check port range
		print "Client port outside of acceptable range"
		print "Must be between 1024 and 65535, and != server port"
		exit(1)
		

if __name__ == "__main__":
	argValidation()
	clientSocket = connectServer()
	sendRecvData(clientSocket)
