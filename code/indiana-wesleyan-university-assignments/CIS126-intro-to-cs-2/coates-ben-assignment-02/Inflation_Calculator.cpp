// Benjamin Coates
// CIS 126
// Chapter 2 Project 7
// Implements a Calculator that calculates infaltion rate a an item over a specified period of time
// ================================================================================================



#include <stdlib.h>
#include <iostream>
#include <iomanip>

int main()
{
    // Welcome message
    std::cout << std::endl << "Welcome to inflation calculator!" << std::endl;
    
    // Message that asks for the item that inflation is being calculated
    // Value is assigned into variable std::string product
    std::string product = "";
    std::cout << "What item are you calculating inflation for? ";
    std::cin >> product;
    
    // Message that asks for the number of items that will be calculated
    // Value is assigned into variable int products
    int products = 0;
    std::cout << "How many " << product << " are we talking about? ";
    std::cin >> products;
    
    // Message that asks for the current cost of the item that will be calculated
    // Value is assigned into variable double cost
    double cost = 0.0;
    std::cout << "How much do " << product << " cost today? ";
    std::cin >> cost;
    
    // Message that asks for the number of years that the calculation will run for
    // Value is assigned into variable int years
    int years = 0;
    std::cout << "How many years out are you thinking? ";
    std::cin >> years;
    
    // Message that asks for the current inflation rate
    // Value is assigned into variable double inflationrate
    double inflationrate = 0.0;
    std::cout << "What is the present inflation rate (in percent format)? ";
    std::cin >> inflationrate;
    std::cout << std::endl;
    
    // Declaration of constants
    const double PERCENTCALC = 0.01;
    const double YEAR_MIN = 0;
    
    // Turns inflationrate into a fraction
    inflationrate = inflationrate * PERCENTCALC;
    
    // Declaration of variable used in and after while loop
    int printyears = 0;
    
    // While loop that prints out the inflated value for the number of years specified by user
    while(years > YEAR_MIN)
    {
        cost = cost + (inflationrate * cost);
        ++printyears;
        std::cout << std::fixed << std::setprecision(2) << "The estimated year "
        << printyears << " cost per item is $" << cost << "." << std::endl;
        --years;
    }
    cost = cost * products;
    std::cout << std::fixed << std::setprecision(2) << "The estimated " << printyears << " year cost of "
    << products << " " << product << " is $" << cost << "." << std::endl;
    
    return EXIT_SUCCESS;
}