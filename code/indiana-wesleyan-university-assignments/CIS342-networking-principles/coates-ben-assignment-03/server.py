# server.py
# CIS-342: Computer Network Fundamentals
# Spring 2016
# Benjamin Coates
# ________________________________________

#import socket module
from socket import *
serverSocket = socket(AF_INET, SOCK_STREAM)

#Prepare a sever socket
serverSocket.bind(('',6789))
serverSocket.listen(1)
while True:

	#Establish the connection
	print 'Ready to serve...'
	connectionSocket, addr = serverSocket.accept()
	try:
                #Receive message from clientSocket
		message = connectionSocket.recv(1024)
		filename = message.split()[1]
		f = open(filename[1:])
		outputdata =  f.read()

		#Send one HTTP header line into socket
		connectionSocket.send("HTTP/1.0 200 OK")

		#Send the content of the requested file to the client
		for i in range(0, len(outputdata)):
			connectionSocket.send(outputdata[i])
		connectionSocket.close()
	except IOError:

		#Send response messasage and file for file not found
		print "Returning 404"
		connectionSocket.send("HTTP/1.0 404 Not Found")
		e = open('error.html')
		t = e.read()
		connectionSocket.send(t)

		#Close client socket
		connectionSocket.close()

#Clost server socket
serverSocket.close()
