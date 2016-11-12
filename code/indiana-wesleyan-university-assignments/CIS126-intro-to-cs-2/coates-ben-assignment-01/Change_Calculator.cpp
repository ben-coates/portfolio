//  Change_Calculator.cpp
//
//  Created by Benjamin Coates on 1/8/15.
//
//	CIS 126: Intro to Computer Science II
//
//  Chapter 1, Excercise 3 pg. 37
//
//  Takes user input of the number and type of coins and returns the value of the coins in US dollars.
// ****************************************************************************************************

#include <stdlib.h>
#include <iostream>
#include <iomanip>

// Declaration of variable for the program.
int quarters, dimes, nickels, pennies, coins;
double value;
std::string quit;
std::string temp;

void Ask_For_Change(std::string change)
// Recursive function
// Precondition: String input is passed in
// Postcondition: Prints a message using the parameter passed in, grabs user input,
// Check to make sure it is valid input. Gives warning message and calls itself if it is bad input.
{
    std::cout << "How many " + change + " do you have?" << std::endl;
    std::cout << "(Type number of " + change + "): ";
    std::cin >> temp;
    while (!std::isdigit(temp[0]))
    {
        std::cout << "Invalid input! Please input integers" << std::endl;
        Ask_For_Change(change);
    }
}

void Reset_Values()
{
    // Precondition: variables exist
    // Postcondition: variables are reset to their original state
    quarters = 0;
    dimes = 0;
    nickels = 0;
    pennies = 0;
    value = 0;
    temp = "";
}

int main ()
{
    // Welcome message
    std::cout << std::endl << "Welcome to the Change Calculator Program!" << std::endl;
    
    // Do while loops that allows for the user to use the program until they want to quit.
    // Runs functions that get user input and assigns values from those inputs
    // Calculates value of user change
    // Prints final message and asks if user would like to continue.
    do
    {
        
        std::cout << std::endl << "Please enter the amount of change you possess when prompted..." << std::endl;
        Ask_For_Change("quarters");
        quarters = atoi(temp.c_str());
        Ask_For_Change("dimes");
        dimes = atoi(temp.c_str());
        Ask_For_Change("nickels");
        nickels = atoi(temp.c_str());
        Ask_For_Change("pennies");
        pennies = atoi(temp.c_str());
        value = (quarters * .25) + (dimes * .10) + (nickels * .05) + (pennies * .01);
        std::cout << "You have $" << std::setprecision(2) << std::fixed << value << " in change!" << std::endl << std::endl;
        Reset_Values();
        std::cout << "If you would like to quit the program type \"QUIT\" and press enter." << std::endl;
        std::cout << "If you would like to calculate more change type any character and press enter." << std::endl;
        std::cin >> quit;
    } while (quit != "QUIT");
    
    return EXIT_SUCCESS;
}