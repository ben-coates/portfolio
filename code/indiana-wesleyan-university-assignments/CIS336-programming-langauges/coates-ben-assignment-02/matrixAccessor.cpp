// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Programming Exercises p. 299, Ex. 4
// =========================================
// Results at the end of document

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

// Function to run the situation of accessing a matrix ONE TRILLION times
void noSubscriptChecking()
{
    // Declares a two dimensional matrix
    std::vector<std::vector<int> > mymatrix( 5, std::vector<int> (10) );
    
    // Initializes random seed
    srand (time(NULL));
    
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();

    
    // Loop that accesses and manipulates matrix ONE TRILLION times without subrscipt range checking
    for ( int i = 0; i <= 1000000000; i++)
    {
        int firstNum = rand() % 4 + 0;
        int secondNum = rand() % 9 + 0;
        mymatrix[firstNum][secondNum] = i;
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"Without subsrcipt checking one trillion accesses took " << diff << " seconds"<<std::endl;
}

void withSubscriptChecking()
{
    // Declares a two dimensional matrix
    std::vector<std::vector<int> > mymatrix( 5, std::vector<int> (10) );
    
    // Initializes random seed
    srand (time(NULL));
    
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    // Loop that accesses and manipulates matrix ONE TRILLION times with subrscipt range checking
    for ( int i = 0; i <= 1000000000; i++)
    {
        int firstNum = rand() % 4 + 0;
        int secondNum = rand() % 9 + 0;
        std::vector<int> temp = mymatrix.at(firstNum);
        temp.at(secondNum) = i;
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"With subsrcipt checking one trillion accesses took " << diff << " seconds"<<std::endl;
}

int main()
{
    noSubscriptChecking();
    withSubscriptChecking();
}

// =======================================================
// Results:
// Accessing a two dimensonal matrix ONE TRILLION times with NON-RANDOM locations
// On my machine
// Without subscript range checking it takes ~ 5.5 sec
// With subscript range checking it takes ~ 280 sec or 4 min 50 sec
//
// Accessing a two dimensonal matrix ONE TRILLION times with RANDOM locations
// Without subscript range checking it takes ~ 20 sec
// With subscript range checking it takes ~ 300 sec or 5 min 10 sec
//
// My conclusions are that range checking dramatically increases the time required to access the
// matrix. The increase in time with random numbers is substantial but is consistent within both non-checked
// checked cases.
