//
//  LabServer.cpp
//
//  Created by Benjamin Coates
//  CIS 126: Intro to Computer Science II
//  Assignment 7/Ch. 12
//  All the code is my own and typed by me.
//  The code creates a server that holds Labs. Allows for functionality, such as
//  logging in, logging off, searching for users and other functionality.

#include <iostream>
#include <stdlib.h>
#include "Lab.h"

// GLOBAL CONSTANTS
const int NUMBEROFLABS = 4;
const int LABONE = 1;
const int LABONESIZE = 5;
const int LABTWO = 2;
const int LABTWOSIZE = 6;
const int LABTHREE = 3;
const int LABTHREESIZE = 4;
const int LABFOUR = 4;
const int LABFOURSIZE = 3;

void deleteServer(Lab* &serverarray)
// Precondition: None
// Postcondition: Deletes all the server array
{
    delete [] serverarray;
}

void initializeServer(Lab* serverarray)
// Precondition: None
// Postcondition: Initializes the labs in serverarray
{
    for(int x = 0; x < NUMBEROFLABS; x++)
    {
        serverarray[x].initializeLab();
    }
}

void printServer(Lab* serverarray)
// Precondition: None
// Postcondition: Prints the labs in  the serverarray
{
    for(int x = 0; x < NUMBEROFLABS; x++)
    {
        serverarray[x].printLab();
    }
}

void login(Lab* &serverarray)
// Precondition: None
// Postcondition: User has been prmoted for labnumber, machinenumber and userid.
// User is logged in on the machine they specified. If they are already logged in
// The loggin will fail. Results outputted to cout stream.
{
    int labnumber;
    int machinenumber;
    std::string userid;
    
    std::cout << "Enter lab number (1 to 4): ";
    std::cin >> labnumber;
    switch (labnumber) {
        case 1:
            std::cout << "Enter computer number (1 to 5): ";
            break;
        case 2:
            std::cout << "Enter computer number (1 to 6): ";
            break;
        case 3:
            std::cout << "Enter computer number (1 to 4): ";
            break;
        case 4:
            std::cout << "Enter computer number (1 to 3): ";
            break;
        default:
            std::cout << "Enter computer Number: ";
            break;
    }
    std::cin >> machinenumber;
    std::cout << "Enter USER ID: ";
    std::cin >> userid;
    
    for(int x = 0; x < NUMBEROFLABS; x++)
       {
           if(serverarray[x].searchForUser(userid) >= 0)
           {
               std::cout << "User is already logged in." << std::endl;
               return;
           }
       }
    if(serverarray[labnumber - 1].userLogin(machinenumber, userid) == true)
    {
        std::cout << "USER ID #" << userid << " successfully LOGGED IN on COMPUTER #"
                  << machinenumber << " in LAB #" << labnumber << std::endl;
    }
    else
    {
        std::cout << "Login Failed!" << std::endl;
    }
    
}

void logoff(Lab* &serverarray)
// Precondition: None
// Postcondition: User has been prompted for userid. The user is then logged off
// If the user is not logged in, the loggoff will fail. Results outputed to cout stream.
{
    std::string userid;
    
    std::cout << "Enter user ID: ";
    std::cin >> userid;
    
    for(int x = 0; x < NUMBEROFLABS; x++)
    {
        if(serverarray[x].userLogoff(userid) == true)
        {
            std::cout << "Logout Successful!" << std::endl;
            return;
        }
    }
    std::cout << "Logout Failed!" << std::endl;

}

void search(Lab* &serverarray)
// Precondition: None
// Postcondition: User has been prompted for a userid. The id has been searched for
// and the results of the search has been outputted to the cout stream
{
    std::string userid;
    
    std::cout << "Enter user ID: ";
    std::cin >> userid;
    
    for(int x = 0; x < NUMBEROFLABS; x++)
    {
        int loc = serverarray[x].searchForUser(userid);
        if(loc >= 0)
        {
            std::cout << "User is logged in on LAB #" << x + 1 << ": COMPUTER #" << loc + 1 << "." << std::endl;
            return;
        }
    }
    std::cout << "User is not logged in." <<std::endl;
}
 
int userPrompt()
// Precondition: None
// Postcondition: Outputs a prompt message.
{
    int userinput;
    std::cout << std::endl;
    std::cout << "Please input" << std::endl;
    std::cout << "1 to Login" << std::endl;
    std::cout << "2 to Logoff" << std::endl;
    std::cout << "3 to Search" << std::endl;
    std::cout << "4 to Quit" << std::endl;
    std::cout << "> ";
    std::cin >> userinput;
    return userinput;
}

int main( )
{
    // Declaration and initialization of the four Labs
    Lab lab1(LABONE, LABONESIZE);
    Lab lab2(LABTWO, LABTWOSIZE);
    Lab lab3(LABTHREE, LABTHREESIZE);
    Lab lab4(LABFOUR, LABFOURSIZE);
    
    // Array that holds the Lab ADTs
    Lab* serverarray = new Lab[NUMBEROFLABS];
    serverarray[0] = lab1;
    serverarray[1] = lab2;
    serverarray[2] = lab3;
    serverarray[3] = lab4;
    
    // Welcome Message
    std::cout << "..............................." << std::endl;
    std::cout << "Welcome to Lab Server" << std::endl;
   
    // Initialize server to empty
    initializeServer(serverarray);
    
    // Variables
    bool end = false;
    
    // Program while loop
    // While loop will not end until case 4 is called
    // Case 4 ends calls the deleteArrays function and end the program
    while(end != true)
    {
        switch (userPrompt())
        {
            case 1: // Login
                login(serverarray);
                printServer(serverarray);
                break;
            case 2: // Logout
                logoff(serverarray);
                printServer(serverarray);
                break;
            case 3: // Search
                search(serverarray);
                printServer(serverarray);
                break;
            case 4: // Quit
                deleteServer(serverarray);
                return EXIT_SUCCESS;
            default:
                printServer(serverarray);
                break;
        }
    }
    std::cout << "..............................." << std::endl;
}