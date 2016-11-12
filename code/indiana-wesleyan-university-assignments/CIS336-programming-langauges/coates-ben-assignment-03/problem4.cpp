// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assignment 3, Problem 4
// =========================================

#include <iostream>

int main () {
    
    int j = 1;
    
    for (int k = (j + 13) / 27; k < 10; k = k + 1)
    {
        int i = 3 * k - 1;
        // Outputs to see operations
        std::cout << i <<std::endl;
    }
    return 0;
}
