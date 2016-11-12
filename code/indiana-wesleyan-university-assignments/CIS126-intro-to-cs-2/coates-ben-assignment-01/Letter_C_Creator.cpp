//  Change_Calculator.cpp
//
//  Created by Benjamin Coates on 1/8/15.
//
//	CIS 126: Intro to Computer Science II
//
//  Chapter 1, Excercise 5 pg. 38
//
//  Takes user inputed character and creates a large letter C using that character.
// *********************************************************************************

#include <stdlib.h>
#include <iostream>

// Declaration of variables
char CHAR;
std::string SPACE = " ";
std::string CTAB = "  ";

int main()
{
    std::cout << "Please input the character you would like to use: " << std::endl;
    std::cin >> CHAR;
    std::cout << SPACE << SPACE << CHAR << SPACE << CHAR << SPACE << CHAR << std::endl;
    std::cout << SPACE << CHAR << CTAB << SPACE << SPACE << CHAR << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout << CHAR << std::endl;
    }
    std::cout << SPACE << CHAR << CTAB << SPACE << SPACE << CHAR << std::endl;
    std::cout << SPACE << SPACE << CHAR << SPACE << CHAR << SPACE << CHAR << std::endl;
    
    return EXIT_SUCCESS;
}
