//
//  LabServer.cpp
//
//  Created by Benjamin Coates
//  CIS 126: Intro to Computer Science II
//  Assignment 6/Ch. 9: Pointers & Dynamic Arrays
//  All the code is my own and typed by me.

#include <iostream>
#include <stdlib.h>

// GLOBAL CONSTANTS
const int NUMBEROFLABS = 4;
const int LABONE = 0;
const int LABONESIZE = 5;
const int LABTWO = 1;
const int LABTWOSIZE = 6;
const int LABTHREE = 2;
const int LABTHREESIZE = 4;
const int LABFOUR = 3;
const int LABFOURSIZE = 3;

void initializeArraysToEmpty(int lab, int size, std::string** &m)
// Precondition: None
// Postcondition: Initializes the array of the lab passed in to empty
{
    for(int x = 0; x < size; x++)
    {
        m[lab][x] = "empty";
    }
}

void initializeAllArrays(std::string** &m)
// Precondition: None
// Postcondition: Initializes all of the arrays in m by using the
// initializeArraysToEmpty function.
{
    initializeArraysToEmpty(LABONE, LABONESIZE, m);
    initializeArraysToEmpty(LABTWO, LABTWOSIZE, m);
    initializeArraysToEmpty(LABTHREE, LABTHREESIZE, m);
    initializeArraysToEmpty(LABFOUR, LABFOURSIZE, m);
}

void printArrays(int lab, int size, std::string** &m)
// Precondition: None
// Postcondition: Prints the array of the lab passed in to cout stream
{
    std::cout << lab + 1 << ":\t";
    for(int j = 0; j < size; j++)
    {
        std::cout << j + 1 << ": " << m[lab][j] << " ";
    }
    std::cout << std::endl;
}

void printAllArrays(std::string** &m)
// Precondition: None
// Postcondition: Prints all of the arrays in m by using the PrintArrays function
{
    printArrays(LABONE, LABONESIZE, m);
    printArrays(LABTWO, LABTWOSIZE, m);
    printArrays(LABTHREE, LABTHREESIZE, m);
    printArrays(LABFOUR, LABFOURSIZE, m);
}

void login(std::string** &m)
// Precondition: None
// Postcondition: Allows a user to login.
// Checks that the Lab and Stations nummbers are valid.
{
    int labnumber;
    int stationnumber;
    std::string idnumber;
    
    // Gets information
    std::cout << "Please Login." << std::endl;
    std::cout << "ID Number: ";
    std::cin >> idnumber;
    std::cout << "Lab Number (1 to 4): ";
    std::cin >> labnumber;
    switch (labnumber) {
        case 1:
            std::cout << "Station Number (1 to 5): ";
            break;
        case 2:
            std::cout << "Station Number (1 to 6): ";
            break;
        case 3:
            std::cout << "Station Number (1 to 4): ";
            break;
        case 4:
            std::cout << "Station Number (1 to 3): ";
            break;
        default:
            std::cout << "Station Number: ";
            break;
    }
    std::cin >> stationnumber;
    
    // Checks the boundaries of the labs
    if(labnumber > NUMBEROFLABS || labnumber < 1)
    {
        std::cout << "That Lab Does Not Exist" << std::endl;
    }
    else if((labnumber == 1 && stationnumber > LABONESIZE) ||
            (labnumber == 2 && stationnumber > LABTWOSIZE) ||
            (labnumber == 3 && stationnumber > LABTHREESIZE) ||
            (labnumber == 4 && stationnumber > LABFOURSIZE) ||
            (stationnumber < 1))
    {
        std::cout << "That Station Does Not Exist" << std::endl;
    }
    else
    {
        m[labnumber - 1][stationnumber - 1] = idnumber;
    }
}

void logoff(std::string** &m)
// Precondition: None
// Postcondition: Logs off the user from the lab and station number.
{
    int labnumber;
    int stationnumber;
    std::string idnumber;
    
    // Gets the information
    std::cout << "To Logoff enter" << std::endl
    << "Lab Number: ";
    std::cin >> labnumber;
    std::cout << "Station Number: ";
    std::cin >> stationnumber;
    std::cout << "ID Number: ";
    std::cin >> idnumber;
    
    // Checks that information inputed is correct
    if(idnumber == m[labnumber - 1][stationnumber - 1])
    {
        m[labnumber - 1][stationnumber - 1] = "empty";
        std::cout << "Successful Logoff!" << std::endl;
    }
    else
    {
        std::cout << "Not logged in on that station." << std::endl;
    }
}

void searchOneArray(std::string idnumber, int lab, int size, int &counter, std::string** &m)
// Precondition: None
// Postcondition: Searches the array passed in for the user id passed in.
// Increaments counter passed in if id is present.
{
    for(int j = 0; j < size; j++)
    {
        if(m[lab][j] == idnumber)
        {
            std::cout << "Lab: " << lab + 1 << " Station: " << j + 1 << std::endl;
            counter++;
            break;
        }
    }
}

void searchAllArrays(std::string idnumber, std::string** &m)
// Precondition: None
// Postcondition: Searches all arrays for the user id by using
// The searchOneArray function. If the counter is equal to zero
// THe user is not logged in.
{
    int counter = 0;
    searchOneArray(idnumber, LABONE, LABONESIZE, counter, m);
    searchOneArray(idnumber, LABTWO, LABTWOSIZE, counter, m);
    searchOneArray(idnumber, LABTHREE, LABTHREESIZE, counter, m);
    searchOneArray(idnumber, LABFOUR, LABFOURSIZE, counter, m);
    if (counter == 0)
    {
        std::cout << "None" << std::endl;
    }
}

void deleteArrays(std::string** &m)
// Precondition: None
// Postcondition: Deletes all the arrays
{
    int i;
    for (i = 0; i < NUMBEROFLABS; i++)
    {
        delete[] m[i];
    }
    delete[] m;
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
    // Delcares first dinemsional array of pointers to pointers to strings
    std::string** m = new std::string*[NUMBEROFLABS];
    
    // Declares second dimensional arrays of pointers to strings
    m[LABONE] = new std::string[LABONESIZE];
    m[LABTWO] = new std::string[LABTWOSIZE];
    m[LABTHREE] = new std::string[LABTHREESIZE];
    m[LABFOUR] = new std::string[LABFOURSIZE];
    
    // Welcome Message
    std::cout << "..............................." << std::endl;
    std::cout << "Welcome to Lab Server" << std::endl;
    
    // Intitlalizes the arrays
    initializeAllArrays(m);
    
    // Variables
    std::string userid;
    bool end = false;
    
    // Program while loop
    // While loop will not end until case 4 is called
    // Case 4 ends calls the deleteArrays functio and end the program
    while(end != true)
    {
        switch (userPrompt())
        {
            case 1:
                login(m);
                printAllArrays(m);
                break;
            case 2:
                logoff(m);
                printAllArrays(m);
                break;
            case 3:
                std::cout << "Input id number you are searching for: ";
                std::cin >> userid;
                searchAllArrays(userid, m);
                break;
            case 4:
                deleteArrays(m);
                return EXIT_SUCCESS;
            default:
                printAllArrays(m);
                break;
        }
    }
    std::cout << "..............................." << std::endl;
}
