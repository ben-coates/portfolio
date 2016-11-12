//
//  NamePopularity.cpp
//  Created by Benjamin Coates on 3/10/15.
//
//  Name: Benjamin Coates
//  Course: CIS-126 Intro to Computer Science 2
//  Assignment: Ch. 6 Programming Project #10 pp. 373-374
//  Description: Program that reads from a specifically formatted file the rank of baby names from 2012
//  It searches for a user inputed name and looks for the rank of the name in both boy and girl names.
//  Reports the results to the user.
//  Statement: This code is my original code. I typed it.
//  ========================================================================================================

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

void welcomeMessage()
// Precondition: None
// Postcondition: Message welcoming the user to the program has been outputted to the console
{
    std::cout << std::endl << std::endl
              << "Welcome to Baby Name Popularity 2012!" << std::endl
              << "Please follow the on screen instructions." << std::endl <<std::endl;
}

void getFirstSearch(std::string &name)
// Precondition: None
// Postcondition: Prompts user for name they would like to search for and passes that name
// into main varible name.
{
    std::cout << "Input the name you would like to look up: ";
    std::cin >> name;
}

void openFile(std::ifstream &filestream)
// Precondition: None
// Postcondition: The file babynames2012.txt has been opened in the file stream passed in
{
    filestream.open("babynames2012.txt");
}

void openFileCheck(std::ifstream &filestream)
// Precondition: None
// Postcondition: Does nothing if file has been opened in file stream.
// If file does not open correctly, prints out a message to console and ends program.
{
    if(filestream.fail())
    {
        std::cout << "Input file opening failed" << std::endl;
        std::exit(1);
    }
}

void checkforName(int &rank, int &boyrank, int &girlrank, std::string &name,
                  bool &boyvalid, bool &girlvalid, std::ifstream &filestream)
// Precondition: None
// Postcondition: Checks the file for the name. If found, assigns the rank of the name to variables
// for boy and girl and sets valid bool equal to true. If not found does nothing.
{
    std::string boyname;
    std::string girlname;
    
    while(!filestream.eof())
    {
        filestream >> rank;
        filestream >> boyname;
        filestream >> girlname;
        
        if(name == boyname)
        {
            boyrank = rank;
            boyvalid = true;
        }
        if(name == girlname)
        {
            girlrank = rank;
            girlvalid = true;
        }
    }
}

void outputData(int &rank, std::string &name, std::string gender, bool &valid)
{
    // Precondition: None
    // Postcondition: If name was in list, prints message with the name and rank and gender of the searched name.
    // If the name was not in the list, prints message that name is not ranked in top 1000.
    if(valid){
        std::cout << name << " is ranked " << rank << " in popularity among " << gender << "." << std::endl;
    }
    else
    {
        std::cout << name << " is not ranked among the top 1000 " << gender << "." << std::endl;
    }
}

void resetValid(bool &boyvalid, bool &girlvalid)
// Precondition: None
// Postcondition: Resets the boyvalid and girl valid bools to false
{
    boyvalid = false;
    girlvalid = false;
}

void closeFile(std::ifstream &filestream)
// Precondition: None
// Postcondition: Closes the file in the filestream passed in.
{
    filestream.close();
}

void getExitOrSearch(std::string &name)
// Precondition: None
// Postcondition: Ask the user if they would like to quit or search again. Puts input into the variable
// passed in.
{
    std::cout << "If you are done searching please type \"DONE\"." << std::endl
              << "If you would like to search again input the name now: ";
    std::cin >> name;
}

void exitMessage()
// Precondition: None
// Postcondition: Displays an exit message upon quitting the program
{
    std::cout << std::endl << "Thank you for using Baby Name Popularity 2012!" << std::endl << std::endl;
}

int main()
{
    // Variable declarations
    int rank;
    int boyrank;
    int girlrank;
    std::string name;
    bool boyvalid = false;
    bool girlvalid = false;
    
    const std::string BOY = "boy";
    const std::string GIRL = "girl";
    
    // Declares the input stream for reading from a file
    std::ifstream in_file_stream;
    
    // Welcome
    welcomeMessage();
    
    // Get user inputed name
    getFirstSearch(name);
    
    // Program Loop
    do
    {
        // Open file
        openFile(in_file_stream);
        
        // Check that file is open
        openFileCheck(in_file_stream);
        
        // Check file for name
        checkforName(rank, boyrank, girlrank, name, boyvalid, girlvalid, in_file_stream);
        
        // Output data
        outputData(boyrank, name, BOY, boyvalid);
        outputData(girlrank, name, GIRL, girlvalid);

        // Formatting line
        std::cout << std::endl;
        
        // Resets the "valid" variables, so that loop will operate correctly.
        resetValid(boyvalid, girlvalid);
        
        // Close file
        closeFile(in_file_stream);
        
        // Get user exit keyword or search keyword
        getExitOrSearch(name);
        
    } while (name.compare("DONE") != 0);
    
    // Exit message
    exitMessage();
    
    return EXIT_SUCCESS;
}