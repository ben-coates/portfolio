// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assignment 3, Problem 3
// =========================================

#include <iostream>
#include <time.h>

void floatOperations ()
{
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    for(int x = 1; x <=100000000; x++)
    {
        
        float y = x + 2.245;
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"100,000,000 float operations take " << diff << " seconds"<<std::endl;
}

void integerOperations ()
{
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    for(int x = 1; x <=100000000; x++)
    {
        int y = x + 2;
    }
    
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"100,000,000 integer operations take " << diff << " seconds"<<std::endl;
}

int main () {
    floatOperations();
    integerOperations();
    
    return 0;
}