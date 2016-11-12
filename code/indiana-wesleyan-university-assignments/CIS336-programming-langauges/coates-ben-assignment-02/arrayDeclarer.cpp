// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Programming Exercises p. 233, Ex. 7
// =========================================
// Results at the end of document

#include <iostream>
#include <time.h>

// Function that declares an array of one trillion integers statically
void staticArray()
{
    static int sArray [1000000000];
}

// Function that delcares an array of one trillion integers on the stack
void stackArray()
{
    int sArray [1000000000];
}

// Function that delcares an array of one trillion integers on the heap and then deletes it
void heapArray()
{
    int *hArray = new int [1000000000];
    delete [] hArray;
}

// Function that times how long it takes to run the staticArray () function one trillion times
// Outputs the result to the cout stream
void runStaticArray()
{
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    // Loop creates 1000000 static arrays
    for(int x = 0; x <= 1000000; x++)
    {
        staticArray();
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"Static Array declarations took " << diff << " seconds"<<std::endl;
}

// Function that times how long it takes to run the stackArray () function one trillion times
// Outputs the result to the cout stream
void runStackArray()
{
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    // Loop creates 1000000 stack arrays
    for(int x = 0; x <= 1000000; x++)
    {
        stackArray();
        
    }

    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"Stack Array declarations took " << diff << " seconds"<<std::endl;
}

// Function that times how long it takes to run the heapArray () function one trillion times
// Outputs the result to the cout stream
void runHeapArray()
{
    // Declares the clocks
    clock_t t1,t2;
    
    // Constructs the first clock
    t1=clock();
    
    // Loop creates 1000000 heap arrays
    for(int x = 0; x <= 1000000; x++)
    {
        heapArray();
        
    }
    
    // Constructs the second clock
    t2=clock();
    
    // Calculates and figures the time taken and outputs it to cout stream
    float diff ((float)t2-(float)t1);
    diff = diff/CLOCKS_PER_SEC;
    std::cout<<"Heap Array declarations took " << diff << " seconds"<<std::endl;
}

// The main function of the program
// Calls the three run functions
int main()
{
    runStaticArray();
    runStackArray();
    runHeapArray();
}

// =======================================================
// Results:
// Decalaring ONE MILLION ARRAYS of ONE TRILLION INTEGERS
// On my machine
// Static arrays take ~ 0.005 sec (usually clocks slightly faster than Stack array)
// Stack arrays take  ~ 0.005 sec (usually clocks slightly slower than Static array)
// Heap arrays take   ~ 12 sec
//
// Declaring ONE TRILLION ARRAYS of ONE TRILLION INTEGERS
// On my machine
// Static arrays take ~ 2.7 sec
// Stack arrays take  ~ 3.2 sec
// Heap arrays take a very long time, waiting a good 5-10 minutes and it hadn't finished
// I tested with a variety of different amounts of arrays, but it leads me to believe that the time it takes
// to declare heap arrays increases exponentially with the amount of arrays being declared
//
// My conclusions are that large heap arrays are extremely time consuming to declare.
// Static arrays and stack array allocation time is extremely similar until the arrays get extremely large.
// Only then do static arrays really have an advantage of time on stack arrays, and the trade off of space
// efficiency might win out.
//
// Finally, I did read some debated thoughts online that clock_t is not always accurate for times under 1 sec.
// That's why I ran a test at a higher time requirement.

