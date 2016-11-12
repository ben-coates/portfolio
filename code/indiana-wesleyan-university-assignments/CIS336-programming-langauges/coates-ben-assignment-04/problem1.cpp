// Benjamin Coates
// Programming Languages
// Passsing Parameters Assignment
// problem1: Array Passing
// October 31st, 2015
// =================================

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

// Declaration of constant
const int ONE = 1;
const int VECTORSIZE = 1000000000;
const long TIMESTOLOOP = 20;

// Empty function that receives a std::vector passed by reference
void passVectorByReference (std::vector<int> &bigVector) {
    
}

// Empty function that receives a std::vector passed by value
void passVectorByValue (std::vector<int> bigVector) {
    
}

// Function that times the amount of time it takes to do the TIMESTOLOOP number
// of calls to the passVectorByReference function
void byReference (std::vector<int> &bigVector) {
    
    // Declares the clocks to be used for timing
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    // For loop that calls the function to be timed for TIMESTOLOOP times
    for (long x = ONE; x < TIMESTOLOOP; x++)
    {
        passVectorByReference(bigVector);
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout << "Passing a vector of "
    << VECTORSIZE << " items "
    << TIMESTOLOOP << " times by reference takes "
    << diff << " seconds"<<std::endl;
}

void byValue (std::vector<int> bigVector) {
    
    // Declares the clocks to be used for timing
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    // For loop that calls the function to be timed for TIMESTOLOOP times
    for (long x = ONE; x < TIMESTOLOOP; x++)
    {
        passVectorByValue(bigVector);
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout << "Passing a vector of "
    << VECTORSIZE << " items "
    << TIMESTOLOOP << " times by value takes "
    << diff << " seconds"<<std::endl;
}


int main () {
    
    // Declares the vector of VECTORSiZE
    std::vector<int> largeVector(VECTORSIZE);
    
    byReference(largeVector);
    byValue(largeVector);
    
    return 0;
}