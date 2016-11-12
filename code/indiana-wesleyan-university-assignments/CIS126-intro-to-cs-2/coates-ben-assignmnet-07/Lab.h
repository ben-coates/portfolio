//
//  Lab.h
//
//  Created by Benjamin Coates
//  CIS 126: Intro to Computer Science II
//  Assignment 7/Ch. 12
//  All the code is my own and typed by me.
//  This code is the header for a Lab class.

#include <iostream>
#include <stdlib.h>

class Lab
{
public:
    // CTORS, DTOR, AND OVERLAODED OPERATORS
    Lab();
    // Default constructor
    // Intializes a empty lab
    
    Lab(int labnumber, int labsize);
    // Constructor
    // Initializes a lab with the number of machines as the integer passed in.
    
    Lab(const Lab &other);
    // Copy Constructor
    // Creates a new Lab exactly the same as the Lab passed in
    
    ~Lab();
    // Destructor.
    // Deletes the Lab
    
    void operator=(const Lab &other);
    // Assignment operator
    // Overloads the assignment operator
    
    // MUTATOR FUNCTIONS
    bool userLogin(int machinenumber, std::string userid);
    // Precondition: machine number > 0 and < size
    // Postcondition: The user has been logged in onto the machine
    // Returns true with successful login and false with unsucessful login.
    
    bool userLogoff(std::string userid);
    // Precondition: None
    // Postcondition: The user has been logged off of the machine
    // Returns true with successful logoff and false with unsucessful logoff.
    
    void initializeLab();
    // Precondition: None
    // Postcondition: The array values have been initalized to empty
   
    // CONST FUNCTIONS
    int searchForUser(std::string userid) const;
    // Precondtion: None
    // Postcondition: The lab has been searched for the user.
    // Returns the machine number the user is on or -1 if the user is not logged in
    
    void printLab() const;
    // Precondtion: None
    // Postcondition: The lab has been printed to the cout stream
    
private:
    int number;
    int size;
    std::string* labarray;
};