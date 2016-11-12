//  TimeMachine.cpp
//  Created by Benjamin Coates on 02/05/15.
//	CIS 126: Intro to Computer Science II
//  Chapter 4, Exercise 7 pg. 249-250
//  Takes a user input start time and future time and comutes the difference.
//  All this code is orginal and was typed by me and me only
// *********************************************************************************

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>

// welcomeMessage()
// Postcondition: Welcome message has been outputed to the console
void welcomeMessage()
{
    std::cout << std::endl;
    std::cout << "Welcome to TimeMachine Calculator!" << std::endl;
    std::cout << std::endl;
}

// resetVariables()
// Precondition: Variables have been declared and passed in
// Postcondition: Variables have been reset to their original state
void resetVariables(int& startHours, int& startMinutes, bool& startIsAM, int& futureHours, int& futureMinutes, bool& futureIsAM)
{
    startHours = 0;
    startMinutes = 0;
    futureHours = 0;
    futureMinutes = 0;
    startIsAM = false;
    futureIsAM = false;
}

// wantToContinue()
// Recursive Function
// Postcondition: Asks the user if they would like to continue.
// Returns the boolean true if they indicate they would like to.
// Returns the boolean false if they indicate they do not.
// Calls recursion if they do not give a correct input, until they do.
bool wantToConintue()
{
    char response[0];
    bool answer = true;
    
    // Ask user if they would like to calculate again
    std::cout << "Would you like to calculate again?" << std::endl;
    std::cout << "Please enter 'Y' or 'N': ";
    
    // Clear buffer and get response
    std::cin.clear();
    std::cin >> response;
    
    // Evaluate response and set value or call function again
    if(strcmp(response, "Y") == 0 || strcmp(response, "y") == 0)
    {
        answer = true;
    }
    else if(strcmp(response, "N") == 0 || strcmp(response, "n") == 0)
    {
        answer = false;
    }
    else
    {
        std::cout << "INVALID INPUT!" << std::endl;
        wantToConintue();
    }
    return answer;
}

// getHours()
// Recursive Function
// Precondition: A string has been passed in
// Postcondition: Returns an integer of the hours inputed by the user.
// Integer will not be less than 1 or greater than 12.
int getHours(int& hours, std::string period)
{
    std::cout << "Please enter the hour of the " + period + " time: ";
    std::cin >> hours;
    if(hours < 1 || hours > 12)
    {
        std::cout << "INVALID INPUT!" << std::endl;
        getHours(hours, period);
    }
    return hours;
}

// getMinutes()
// Recursive Function
// Precondition: A string has been passed in
// Postcondition: Returns an integer of the minutes inputed by the user.
// Integer will not be less than 0 or greater than 59.
int getMinutes(int& minutes, std::string period)
{
    std::cout << "Please enter the minutes of the " + period + " time: ";
    std::cin >> minutes;
    if(minutes < 0 || minutes > 59)
    {
        std::cout << "INVALID INPUT!" << std::endl;
        getMinutes(minutes, period);
    }
    return minutes;
}

// getIsAM()
// Recursive Function
// Postcondition: Returns a bool of whether time inputed is AM or PM
bool getIsAM()
{
    char char_a[1];
    bool isAM = false;
    
    // Ask user whether AM or PM
    std::cout << "Please enter whether time is AM or PM using 'A' or 'P': ";
    std::cin.clear();
    std::cin >> char_a;
    
    // Evaluate response and set value or call function again
    if(strcmp(char_a, "A") == 0 || strcmp(char_a, "a") == 0)
    {
        isAM = true;
    }
    else if (strcmp(char_a, "P") == 0 || strcmp(char_a, "p") == 0)
    {
        isAM = false;
    }
    else
    {
        std::cout << "INVALID INPUT!" << std::endl;
        getIsAM();
    }
    return isAM;
}

// getTime()
// Precondition: Parameters has been initialized and passed in
// Postcondition: Calls for each of the functions required to get the time from the user.
// Prints a empty line to the console at the end of the console stream.
void getTime(int& hours, int & minutes, bool& isAM, std::string period)
{
    hours = getHours(hours, period);
    minutes = getMinutes(minutes, period);
    isAM = getIsAM();
    std::cout << std::endl;
}

// calculateStartTime()
// Precondition: Parameters have been initialized and passed in
// Postcondition: Returns integer of the number of minutes the time
// recieved is from 00:00.
int calculateTimeInMinutes(int hours, int minutes, bool isAm)
{
    const int HOUR = 60;
    const int TWELVEHOURS = 720;
    
    // Cacluate AM time
    if(isAm == true)
    {
        if(hours == 12)
        {
            hours = 0;
        }
        hours = hours * HOUR;
        minutes = hours + minutes;
        return minutes;
    }
    
    // Calculate PM time
    if(hours == 12)
    {
        hours = 0;
    }
    hours = (hours * HOUR) + TWELVEHOURS;
    minutes = hours + minutes;
    return minutes;
}

// computeDifference()
// Precondition: Parameters have been initialized and passed in
// Postcondition: Retruns the difference between the start time and future time.
// If the start time is past the future time, it tells the user and reverses the calculation.
int computeDifference(int startHours, int startMinutes, bool startIsAM, int futureHours, int futureMinutes, bool futureIsAM)
{
    int sMinutes;
    int fMinutes;
    int difMinutes;
    
    // Calculate start time
    sMinutes = calculateTimeInMinutes(startHours, startMinutes, startIsAM);
    
    // Calculate future time
    fMinutes = calculateTimeInMinutes(futureHours, futureMinutes, futureIsAM);
    
    // Calculate difference time
    difMinutes = fMinutes - sMinutes;
    
    // If start time is after future time special case output message
    if(difMinutes < 0)
    {
        std::cout << "Future time is before start time." << std::endl;
        std::cout << "Maybe you got your times switched." << std::endl;
        std::cout << "In that case the time difference would be ";
        return sMinutes - fMinutes;
    }
    return difMinutes;
}

// Main
int main ()
{
    int startHours = 0;
    int startMinutes = 0;
    int futureHours = 0;
    int futureMinutes = 0;
    bool startIsAM = false;
    bool futureIsAM = false;
    std::string start = "start";
    std::string future = "future";
    
    // Welcome
    welcomeMessage();
    
    // Do while loop that ask user if they would like to continue.
    do{
        // Get Start and Future times
        getTime(startHours, startMinutes, startIsAM, start);
        getTime(futureHours, futureMinutes, futureIsAM, future);
        
        // Set time to int and convert to string
        int timeDifference = computeDifference(startHours, startMinutes, startIsAM, futureHours, futureMinutes, futureIsAM);
        std::ostringstream convert;
        convert << timeDifference;
        std::string time = convert.str();
        
        // Out put the time difference
        std::cout << "The difference between the start time and future time is " + time + " minutes" << std::endl;
        
        // reset the variables
        resetVariables(startHours, startMinutes, startIsAM, futureHours, futureMinutes, futureIsAM);
    } while(wantToConintue() == true);
    
    return 0;
}