// File name:       Change_Calculator.cpp
// Author:          Benjamin Coates
// Date:            Thursday, February 12, 2015
// Last Update:     Thursday, February 12, 2015
//
// Programming Project 4
// Chapter 5: Exercise 4 pages 299 and 300
// All the code in this file is original and was typed by me only
// =========================================================================

#include <iostream>
#include <cstdlib>
#include <cassert>

void welcomeMessage()
// Precondition: None
// Postcondition: Three blank lines and a greeting have been outputted
// to the console
{
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Welcome to Change Calculator!!!" << std::endl;
}

void getInput(int& amount_left)
// Recursive function
// Precondition: None
// Postcondition: User has been asked to input an integer value
// for the amount of cents to be changed. Parameter passed in has
// been set to an integer value between 0 (inclusive) and 100 (exclusive)
{
	// Getting user input
    std::cout << "Please input amount of cents (integer value) that need changed: ";
    std::cin >> amount_left;
    std::cin.ignore();
    
    // Cheking to see that it is between 0 and 100
    if(amount_left < 0 or amount_left >= 100)
    {
        std::cout << "Amount must be between 0 (inclusive) and 100 (exclusive)," << std::endl;
        
        // Recursive call
        getInput(amount_left);
    }
    std::cout << std::endl;
}

void compute_coins(int coin_value, int& num, int& amount_left)
// Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
// Postcondition: num has been set equal to the maximum number
// of coins of denomination coin_value cents that can be obtained
// from amount_left. Additionally, amount_left has been decreased
// by the value of the coins, that is, decreased by
// num * coin_value.
{
	// Checking precondition
	assert(coin_value > 0 and coin_value < 100);
	assert(amount_left >= 0 and amount_left < 100);
	
	// Setting number of coins for type
	num = amount_left / coin_value;
	
	// Setting amount left after cents of coin type removed
	amount_left = amount_left % coin_value;
}

void sendOutput(int first_amount, int numberOfQuarters, int numberOfDimes, int numberOfPennies)
// Precondition: None
// Postcondition: The originally inputted cent amount as well as
// the number of quaters, dimes and pennies needed to make the change
// has been outputted to the console
{
	std::cout << first_amount << " cents can be given as" << std::endl;
	std::cout << numberOfQuarters << " quarter(s) "
              << numberOfDimes << " dimes(s) "
              << numberOfPennies << " penny(pennies)" << std::endl << std:: endl;
}

void calculateAgain(bool& finished)
// Precondition: None
// Postcondition: Ask user if they would like to continue,
// Sets the boolean passed in to false if they would like to continue.
// Sets the boolean to true if they are finished
{
    char answer;
    
    std::cout << "Would you like to calculate again?" << std::endl;
    std::cout << "Please enter Yes (Y) or No (N): ";
    std::cin.get(answer);
    
    if(answer == 'Y' or answer == 'y')
    {
        finished = false;
        std::cout << std::endl << std::endl;
    }
    else
    {
        finished = true;
        std::cout << "Thanks for using Change Calculator!" << std::endl;
        std::cout << std::endl << std::endl;
    }
}

int main()
{
    // CONSTANT DECLARATIONS
    const int QUARTER = 25;
    const int DIME = 10;
    const int PENNY = 1;
    
    // Variable Declarations
    int numberOfQuarters;
	int numberOfDimes;
	int numberOfPennies;
	int amount_left;
	int first_amount;
    bool finished = false;
    
    // Welcome Message
    welcomeMessage();
    
	// Loop
	do
	{
		// Ask for change
		getInput(amount_left);
		first_amount = amount_left;
		
		// Compute change
		compute_coins(QUARTER, numberOfQuarters, amount_left);
		compute_coins(DIME, numberOfDimes, amount_left);
		compute_coins(PENNY, numberOfPennies, amount_left);
		
		// return input
		sendOutput(first_amount, numberOfQuarters, numberOfDimes, numberOfPennies);
        
        // Check for completion
        calculateAgain(finished);
        
	} while(!finished);
		
	return EXIT_SUCCESS;
}