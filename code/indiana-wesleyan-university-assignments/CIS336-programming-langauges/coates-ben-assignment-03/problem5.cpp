// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assignment 3, Problem 5
// =========================================

#include <iostream>
#include <vector>

int main () {
    
    // Declares a two dimensional matrix
    std::vector<std::vector<int> > x( 10, std::vector<int> (10) );
    
    // Loop that accesses all matrix locations and gives them the value of 1
    for (int i = 0; i < 10; i++)
    {
        for(int j= 0; j < 10; j++) {
            x[i][j] = 1;
        }
    }
    
     // Loop that accesses matrix locations and gives them the value of 0 starting at row 4 (fifth row)
    for (int i = 4; i < 10; i++)
    {
        for(int j= 0; j < 10; j++) {
            x[i][j] = 0;
        }
    }
    
    int n = 10;
    
    for(int i = 1; i <=n; ++i)
    {
        for(int j = 1; j <= n; j++) {
            if (x[i][j] != 0) {
                break;
            }
            else
            {
                // Message does not change value for easier understanding.
                // First row is row 0
                std::cout << "First all-zero row is: " << i <<std::endl;
                return 0;
            }
        }
    }
    return 0;
}
