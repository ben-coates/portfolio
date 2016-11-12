// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assignment 3, Problem 6
// =========================================

#include <iostream>
#include <vector>

int main () {
    
    int x = 4;
    int y;
    
    if(x > 10)
    {
        y = x;
    }
    else if(x < 5)
    {
        y = 2 * x;
    }
    else if(x == 7)
    {
        y = x + 10;
    }
    // Final else statment not required, but improves readability
    else
    {
        // Do nothing
    }
    // Output message for testing purposes
    std::cout << y << std::endl;
}
