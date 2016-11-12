# UDPPingerClient.py
# Benjamin Coates
# CIS -342: Computer Network Fundamentals
# Spring 2016
# ________________________________________

import time
from socket import *

# Set up client socket, settimeout, and set server address
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1)
serverAddress = ('', 12000)

# Send 10 pings to server
for sequence_number in range(1,11):
    try:
        # Set up message
        ping = "Ping " + str(sequence_number) + " " + str(time.ctime())

        # Start timer, Send message to server, Calculate RTT
        start = time.time()
        clientSocket.sendto((ping), serverAddress)
        message, address = clientSocket.recvfrom(1024)
        end = time.time()
        total = end - start

        # Print return message and RTT message
        print message
        print "RTT: "+ str(total) + ' sec'   # Assumes ticks are sec (couldn't find documentation on it)
        print
    except timeout:
        
        # Otherwise print request timed out
        print "Request timed out"
        print


