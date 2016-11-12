// Benjamin Coates
// Programming Languages
// Passsing Parameters Assignment
// problem2-1: Reference vs. Value Passing
// October 31st, 2015
// =================================

#include <iostream>

void swapTheIntegers(int x, int y) {
    // Output the data before swap happens
    std::cout << "Before the Swap" << std::endl
    << "Int x = " << x << std::endl
    << "Int y = " << y << std::endl;

    // Perform swap
    int temp = x;
    x = y;
    y = temp;
    
    // Output the data after swap happens
    std::cout << "After the Swap" << std::endl
    << "Int x = " << x << std::endl
    << "Int y = " << y << std::endl;

}

int main () {
    // Declarations of variables
    int x = 20;
    int y = 24;
    
    // Function Calls and Outputs
    std::cout << "First Swap" << std::endl;
    swapTheIntegers(x, y);
    std::cout << std::endl << std::endl;
    
    std::cout << "Second Swap" << std::endl;
    swapTheIntegers(x, y);
    std::cout << std::endl;
}