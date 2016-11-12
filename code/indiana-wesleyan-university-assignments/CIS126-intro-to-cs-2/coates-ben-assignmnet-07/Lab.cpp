//
//  Lab.cpp
//
//  Created by Benjamin Coates
//  CIS 126: Intro to Computer Science II
//  Assignment 7/Ch. 12
//  All the code is my own and typed by me.
//  This code is the implementation for a Lab class.

#include <iostream>
#include <stdlib.h>
#include "Lab.h"
#include <cassert>


// CTORS, DTOR, AND OVERLAODED OPERATORS
Lab::Lab ()
// Default constructor.
// Intializes a empty lab
{
    
}

Lab::Lab(int labnumber, int labsize)
// Constructor
// Initializes a lab with the number of machines as the integer passed in.
{
    number = labnumber;
    size = labsize;
    labarray = new std::string[size];
}

Lab::Lab(const Lab &other)
// Copy Constructor
// Creates a new Lab exactly the same as the Lab passed in
{
    labarray = new std::string[other.size];
    for(int x = 0; x < other.size; x++)
    {
        labarray[x] = other.labarray[x];
    }
    number = other.number;
    size = other.size;
}

Lab::~Lab()
// Destructor.
// Deletes the Lab
{
    delete [] labarray;
}

// MUTATOR FUNCTIONS
void Lab::operator=(const Lab &other)
// Assignment operator
// Overloads the assignment operator
{
    labarray = new std::string[other.size];
    for(int x = 0; x < other.size; x++)
    {
        labarray[x] = other.labarray[x];
    }
    size = other.size;
}

bool Lab::userLogin(int machinenumber, std::string userid)
// Precondition: machine number > 0 and < size
// Postcondition: The user has been logged in onto the machine.
// Returns true with successful login and false with unsucessful login.
{
    if(machinenumber > 0 && machinenumber <= size)
    {
        if(labarray[machinenumber - 1] != "empty")
        {
            return false;
        }
        labarray[machinenumber - 1] = userid;
        return true;
    }
    else
    {
        return false;
    }
}

bool Lab::userLogoff(std::string userid)
// Precondition: None
// Postcondition: The user has been logged off of the machine
{
    if(Lab::searchForUser(userid) >= 0)
    {
        labarray[Lab::searchForUser(userid)] = "empty";
        return true;
    }
    else
    {
        return false;
    }
}

void Lab::initializeLab()
// Precondition: None
// Postcondition: The array values have been initalized to empty
{
    for(int i = 0; i < size; i++)
    {
        labarray[i] = "empty";
    }
}

// CONST FUNCTIONS
int Lab::searchForUser(std::string userid) const
// Precondtion: None
// Postcondition: The lab has been searched for the user.
// Returns the machine number the user is on or zero if the user is not logged in
{
    bool ispresent = false;
    int location;
    for(int i = 0; i < size; i++)
    {
        if(labarray[i] == userid)
        {
            location = i;
            ispresent = true;
        }
    }
    if(ispresent == true)
    {
        return location;
    }
    else
    {
        return -1;
    }
}

void Lab::printLab() const
// Precondtion: None
// Postcondition: The Lab has been printed to the cout stream
{
    std::cout << number << ":\t";
    for(int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ": " << labarray[i] << " ";
    }
    std::cout << std::endl;
}
