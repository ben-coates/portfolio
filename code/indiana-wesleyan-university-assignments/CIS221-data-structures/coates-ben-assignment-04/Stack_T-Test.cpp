// File: Stack_T-Test.cpp
//
// Author: Benjamin Coates and Aaron Cawthorn
// Course: CIS 221 - Data Structures
// Assignment: Lab 4 - Stack
//
// Purpose: Testing file for templatized stack class.

// Standard headers
#include <iostream>
#include "Stack_T.h"

// This typedef is useful if you want to stack characters.
typedef Stack<char> CSTACK;

// Declares a integer to hold the number of points earned
int points = 0;

// **************************************************************************
// Function that adds one to the points integer and prints the end of test message.
// **************************************************************************
void test_end()
{
	std::cout << "All tests passed for this Test!" << std::endl;
	++points;
	std::cout << "So far, you have passed " << points << " of 7 tests possible." << std::endl << std::endl << std::endl;
}

// **************************************************************************
// Function that prints out a test failed message.
// **************************************************************************
void test_fail()
{
	std::cout << "TEST FAILED!!!" << std::endl << std::endl;
}

// **************************************************************************
// Precondition: Arguement is a CSTACK
// Postcondition: Function returns true if underflow is thrown.
// Returns false if it is not thrown.
// **************************************************************************
bool underflow_test(CSTACK stack)
{
	try
	{
		stack.pop();
	}
	catch (Stack<char>::Underflow)
	{
		std::cout << "Underflow Thrown." << std::endl;
		return true;
		// return 0 ends function so that true & false will not both be returned
		return 0;
	}
		return false;
}

// **************************************************************************
// Precondition: Arguements are a CSTACK, char, and int.
// Postcondition: Function returns true if verification is met
// Returns false if it is not.
// **************************************************************************
bool top_item_verification(CSTACK stack, char let, size_t num)
{
	if(stack.top() != let)
	{
		test_fail();
		return false;
		return 0;
	}
	if(stack.size() != num)
	{
		test_fail();
		return false;
		return 0;
	}
	return true;
}

// **************************************************************************
// Test 1: Tests popping an element from an empty stack and making sure that underflow is thrown.
// **************************************************************************
int test1()
{
	std::cout << std::endl; // Formatting line: Adds a blank line at top of output
	std::cout << "BEGINNING TEST 1:" << std::endl;
	std::cout << "Testing to see that underflow is thrown correctly." << std::endl;
	
	// Declares a stack
	std::cout << "Creating a stack called A_stack." << std::endl;
	CSTACK A_stack;
	
	// Tests to see that underflow is thrown
	std::cout << "Testing to see that underflow is thrown on a stack with no items in it." << std::endl;
	if (underflow_test(A_stack) != true)
	{
		test_fail();
		return 0;
	}
	
	// Adds an item to the stack
	A_stack.push('a');
	
	// Tests to make sure that underflow is not thrown on a stack with an item in it.
	std::cout << "Testing to see that underflow is not thrown on a stack with items in it." << std::endl;
	if (underflow_test(A_stack) != false)
	{
		test_fail();
		return 0;
	}
	std::cout << "Underflow not thrown." << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 2: Tests the copy constructor.
// Does not use the equality and inequality operators to perform the tests.
// **************************************************************************
int test2 ()
{
	std::cout << "BEGINNING TEST 2:" << std::endl;
	std::cout << "Testing to see that the copy constucor works correctly." << std::endl;
	
	// Declares a stack
	std::cout << "Creating a stack called A_stack." << std::endl;
	CSTACK A_stack;
	
	// Adds characters 'a', 'b', and 'c' to A_stack and verfies them while adding
	std::cout << "Adding the characters 'a', 'b', and 'c' to A_stack." << std::endl;
	std::cout << "Checking to make sure they are correct as they are added." << std::endl;
	
	// Adds character 'a' to A_stack and checks size
	std::cout << "Adding 'a' to A_stack." <<std::endl;
	A_stack.push('a');
	std::cout << "Using the top function to check that 'a' has been added to the A_stack and that checking size equals 1." <<std::endl;
	if(top_item_verification(A_stack, 'a', 1) != true)
	{
		return 0;
	}
	std::cout << "'" <<A_stack.top() << "' has been added to the A_stack." << std::endl;
	
	// Adds character 'b' to A_stack  and checks size
	std::cout << "Adding 'b' to A_stack." <<std::endl;
	A_stack.push('b');
	std::cout << "Using the top function to check that 'b' has been added to the A_stack and checking that size equals 2." <<std::endl;
	if(top_item_verification(A_stack, 'b', 2) != true)
	{
		return 0;
	}
	std::cout << "'" << A_stack.top() << "' has been added to the A_stack." << std::endl;
	
	// Adds character 'c' to A_stack and checks size
	std::cout << "Adding 'c' to A_stack." <<std::endl;
	A_stack.push('c');
	std::cout << "Using the top function to check that 'a' has been added to the A_stack and checking that size equals 3." <<std::endl;
	if(top_item_verification(A_stack, 'c', 3) != true)
	{
		return 0;
	}
	std::cout << "'" << A_stack.top() <<"' has been added to the A_stack." << std::endl;
	
	// Declares and copies A_Stack into a new CSTACK called B_Stack
	std::cout << "Making a copy of A_stack called B_stack, and then checking to make sure it is correct" << std::endl;
	CSTACK B_stack(A_stack);
	
	// Loop that checks to make sure all items in B_stack, match A_stack
	std::cout << "Checking to makes sure B_stack is a correct copy of A_stack" << std::endl;
	while(B_stack.size() > 0)
	{
		if(top_item_verification(B_stack, A_stack.top(), A_stack.size()) != true)
		{
			return 0;
		}
		A_stack.pop();
		B_stack.pop();
	}
	std::cout << "B_stack was a corect copy of A_stack" << std::endl << std::endl;
	
	// Performs and overflow test on A_stack and B_stack
	std::cout << "Testing to make sure that A_stack and B_stack are both empty." << std::endl;
	if(underflow_test(A_stack) != true)
	{
		test_fail();
		return 0;
	}
	if(underflow_test(B_stack) != true)
	{
		test_fail();
		return 0;
	}
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 3: Tests the equality and inequality operators
// **************************************************************************
int test3()
{
	std::cout << "BEGINNING TEST 3:" << std::endl;
	std::cout << "Testing the equality and inequality operators." << std::endl;
	
	// Declares six stacks for testing
	std::cout << "Creating six stacks A_stack,B_stack ,C_stack, D_stack, E_stack & F_stack" << std::endl << std::endl;
	CSTACK A_stack, B_stack, C_stack, D_stack, E_stack, F_stack;
	
	// Pushes three characters onto A_stack
	std::cout << "Pushing 'a', 'b', and 'c' onto A_stack" << std::endl;
	A_stack.push('a');
	A_stack.push('b');
	A_stack.push('c');
	
	// Pushes three characters onto B_stack
	std::cout << "Pushing 'a', 'b', and 'c' onto B_stack" << std::endl;
	B_stack.push('a');
	B_stack.push('b');
	B_stack.push('c');
	
	// Pushes three characters onto C_stack
	std::cout << "Pushing 'e', 'f', and 'g' onto C_stack" << std::endl;
	C_stack.push('e');
	C_stack.push('f');
	C_stack.push('g');
	
	// Pushes four characters onto D_stack
	// Intentionally pushes 'd' on first for later test becuase of LIFO structure of stacks
	std::cout << "Pushing 'a', 'b', 'c' and 'd' onto D_stack" << std::endl;
	D_stack.push('d');
	D_stack.push('a');
	D_stack.push('b');
	D_stack.push('c');
	
	// Output message to alert user that there are two empty stacks
	std::cout << "E_stack is empty" << std::endl;
	std::cout << "F_stack is empty" << std::endl << std::endl;
	
	// Tests two stacks that are empty for equality
	std::cout << "Testing to see if two empty stacks are equal." << std::endl;
	std::cout << "Testing to see if E_stack is equal to F_stack!" << std::endl;
	if (E_stack!=(E_stack))
	{
		test_fail();
		return 0;
	}
	std::cout << "E_stack is equal to F_stack...Passed" << std::endl;
	
	// Tests two stacks that are equal
	std::cout << "Testing to see if equal stacks are equal." << std::endl;
	std::cout << "Testing to see if A_stack is equal to B_stack!" << std::endl;
	if (A_stack!=(B_stack))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack is equal to B_stack...Passed" << std::endl;
	
	// Tests two stacks that have the same number of items but are not equal
	std::cout << "Testing to see if two sequences with the same amount of items are not equal." << std::endl;
	std::cout << "Testing to see if A_stack is equal to C_stack!" << std::endl;
	if (A_stack==(C_stack))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack is not equal to C_stack...Passed" << std::endl;
	
	// Tests two stacks that have different number of items but the same items in the first 3 spots.
	std::cout << "Testing to see if two sequences with different amounts of items," << std::endl;
	std::cout << "but the same items in the first three spots the are not equal." << std::endl;
	std::cout << "Testing to see if A_stack is equal to D_stack!" << std::endl;
	if (A_stack==(D_stack))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack is not equal to D_stack!...Passed" << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 4: Tests the assignment operator
// **************************************************************************
int test4()
{
	std::cout << "BEGINNING TEST 4:" << std::endl;
	std::cout << "Testing the assignment operator." << std::endl;
	
	// Declares two stacks A_stack, B_stack, and C_stack.
	std::cout << "Creating three stacks called A_stack, B_stack, and C_stack." << std::endl;
	CSTACK A_stack;
	CSTACK B_stack;
	CSTACK C_stack;
	
	// Adds three characters to A_stack
	std::cout << "Adding three characters: 's', 't', and 'u' to A_stack." << std::endl;
	A_stack.push('s');
	A_stack.push('t');
	A_stack.push('u');
	
	// Checks to make sure A_stack has three characters in it
	std::cout << "Checking to makes sure A_stack has three character in it." << std::endl;
	if(A_stack.size() != 3)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack has three character in it." << std::endl;
	
	// Tests to make sure that A_stack and C_stack are not the same
	std::cout << "C_Stack is an empty stack. Testing to make sure A_stack and C_stack are not the same." <<std::endl;
	if(A_stack==(C_stack))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack and C_stack are not the same." << std::endl << std::endl;
	
	// Uses the assignment operator to make B_stack equal to A_stack
	// and tests to make sure that A_stack and B_stack are equal.
	std::cout << "Assigning B_stack to equal A_stack." << std::endl;
	B_stack=A_stack;
	std::cout << "Testing to make sure A_stack and B_stack are the same." <<std::endl;
	if(B_stack!=(A_stack))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack and B_stack are equal." << std::endl << std::endl;
	
	// Uses the assignment operator to make A_stack equal C_stack, which is an empty stack;
	// And test to make sure that A_stack and C_stack are equal.
	std::cout << "Assinging A_stack to equal C_stack, which is still empty." << std::endl;
	A_stack=C_stack;
	std::cout << "Testing to make sure A_stack and C_stack are the same." <<std::endl;
	if(A_stack!=(C_stack))
	{
		test_fail();
		return 0;
	}
	std:: cout << "A_stack and C_stack are equal." << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 5: Tests popping and topping all elements to get Underflow
// **************************************************************************
int test5()
{
	std::cout << "BEGINNING TEST 5:" << std::endl;
	std::cout << "Testing popping all elements until we get an Underflow exception." << std::endl;
	std::cout << "Testing topping on an empty stack and makes sure that Underflow is thrown." <<std::endl;
	std::cout << "Adding three characters to a stack and popping all items until underflow is thrown" << std::endl;

	// Declares a stack
	std::cout << "Creating a stack called A_stack." << std::endl;
	CSTACK A_stack;
	
	// Adds three characters to the stack
	std::cout << "Adding 'a', 'b', and 'c' to A_stack." << std::endl;
	A_stack.push('a');
	A_stack.push('b');
	A_stack.push('c');
	
	// Pops the elements off the stack until underflow is thrown, then catches the exception.
	std::cout << "Popping the elements of the stack so that underflow is thrown." << std::endl;
	while (A_stack.size() > 0)
	{
		A_stack.pop();
	}
	if (underflow_test(A_stack) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "Underflow thrown correctly." << std::endl << std::endl;
	
	// Uses the top function to elict an Underflow exception
	std::cout << "Testing that using the top function on A_stack throws the underflow exception" << std::endl;
	int answer = 0;
	try
	{
		A_stack.top();
	}
	catch (Stack<char>::Underflow)
	{
		std::cout << "Underflow Thrown." << std::endl;
		++answer;
	}
	if (answer != 1)
	{
		test_fail();
		return 0;
	}
	std::cout << "Underflow thrown correctly." << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 6: Tests the is_empty function
// **************************************************************************
int test6()
{
	std::cout << "BEGINNING TEST 6:" << std::endl;
	std::cout << "Testing to make sure the is_empty function works correctly." << std::endl;
	
	// Declares stacks
	std::cout << "Creating two stacks called A_stack and B_stack." << std::endl;
	CSTACK A_stack;
	CSTACK B_stack;
	
	// Adds a character to A_stack and test to make sure it is not empty
	std::cout << "Adding chracter to A_stack so that it not longer empty" << std::endl;
	A_stack.push('a');
	std::cout << "Testing to see that A_stack is not empty." << std::endl;
	if (A_stack.is_empty() != false)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack is not empty." << std::endl << std::endl;
	
	// Tests to make sure that B_stack is empty
	std::cout << "Testing to see that B_stack is empty." << std::endl;
	if (B_stack.is_empty() != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "B_stack is empty." << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 7: Tests the pushing, popping and topping of items extensively
// **************************************************************************
int test7()
{
	std::cout << "BEGINNING TEST 7:" << std::endl;
	std::cout << "Testing the pushing, popping, and topping of character on a stack." << std::endl;
	
	// Declares four stacks
	std::cout << "Creating four stacks A_stack, B_stack, C_stack and D_stack." << std::endl << std::endl;
	CSTACK A_stack;
	CSTACK B_stack;
	CSTACK C_stack;
	CSTACK D_stack;
	
	// Pushes three characters onto A_stack
	std::cout << "Pushing 'a', 'b', and 'c' onto A_stack" << std::endl;
	A_stack.push('a');
	A_stack.push('b');
	A_stack.push('c');
	
	// Pushes three characters onto B_stack
	std::cout << "Pushing 'a', 'b', and 'c' onto B_stack" << std::endl;
	B_stack.push('a');
	B_stack.push('b');
	B_stack.push('c');
	
	// Pushes three characters onto C_stack
	std::cout << "Pushing 'e', 'f', and 'g' onto C_stack" << std::endl;
	C_stack.push('e');
	C_stack.push('f');
	C_stack.push('g');
	
	// Pushes four characters onto D_stack
	std::cout << "Pushing 'a', 'b', 'c' and 'd' onto D_stack" << std::endl;
	D_stack.push('d');
	D_stack.push('a');
	D_stack.push('b');
	D_stack.push('c');
	
	// Uses pop and top to check A_Stack, and then checks to make sure it is empty.
	std::cout << "Using top and pop to check that A_stack is accurate." << std::endl;
	if(top_item_verification(A_stack, 'c', 3) != true)
	{
		return 0;
	}
	A_stack.pop();
	if(top_item_verification(A_stack, 'b', 2) != true)
	{
		return 0;
	}
	A_stack.pop();
	if(top_item_verification(A_stack, 'a', 1) != true)
	{
		return 0;
	}
	A_stack.pop();
	std::cout << "A_stack was correct." << std::endl;
	std::cout << "Checking to make sure A_stack is empty." << std::endl;
	if (underflow_test(A_stack) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_stack is empty." << std::endl << std::endl;
	
	// Uses pop and top to check B_Stack, and then checks to make sure it is empty.
	std::cout << "Using top and pop to check that B_stack is accurate." << std::endl;
	if(top_item_verification(B_stack, 'c', 3) != true)
	{
		return 0;
	}
	B_stack.pop();
	if(top_item_verification(B_stack, 'b', 2) != true)
	{
		return 0;
	}
	B_stack.pop();
	if(top_item_verification(B_stack, 'a', 1) != true)
	{
		return 0;
	}
	B_stack.pop();
	std::cout << "B_stack was correct." << std::endl;
	std::cout << "Checking to make sure B_stack is empty." << std::endl;
	if (underflow_test(B_stack) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "B_stack is empty." << std::endl << std::endl;
	
	// Uses pop and top to check C_Stack, and then checks to make sure it is empty.
	std::cout << "Using top and pop to check that C_stack is accurate." << std::endl;
	if(top_item_verification(C_stack, 'g', 3) != true)
	{
		return 0;
	}
	C_stack.pop();
	if(top_item_verification(C_stack, 'f', 2) != true)
	{
		return 0;
	}
	C_stack.pop();
	if(top_item_verification(C_stack, 'e', 1) != true)
	{
		return 0;
	}
	C_stack.pop();
	std::cout << "C_stack was correct." << std::endl;
	std::cout << "Checking to make sure C_stack is empty." << std::endl;
	if (underflow_test(C_stack) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "C_stack was empty." << std::endl << std::endl;
	
	// Uses pop and top to check D_Stack
	std::cout << "Using top and pop to check that D_stack is accurate." << std::endl;
	if(top_item_verification(D_stack, 'c', 4) != true)
	{
		return 0;
	}
	D_stack.pop();
	if(top_item_verification(D_stack, 'b', 3) != true)
	{
		return 0;
	}
	D_stack.pop();
	if(top_item_verification(D_stack, 'a', 2) != true)
	{
		return 0;
	}
	D_stack.pop();
	if(top_item_verification(D_stack, 'd', 1) != true)
	{
		return 0;
	}
	D_stack.pop();
	std::cout << "D_stack was correct." << std::endl;
	std::cout << "Checking to make sure D_stack is empty." << std::endl;
	if (underflow_test(D_stack) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "D_stack was empty." << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

int main (int argc, char *argv[])
{
	// Tests popping an element from an empty stack and making sure that underflow is thrown.
	test1();
	
	// Tests the copy constructor.
	test2();
	
	// Tests the equality and inequality operators.
	test3();
	
	// Tests the assignment operator, by using the equality and inequality operators.
	test4();
	
	// Tests popping all elements until we get an Underflow exception.
	// Tests topping on an empty stack and makes sure that underflow is thrown.
	test5();
	
	// Tests stacks for being empty.
	test6();
	
	// Tests pushing, popping and topping of elements.
	test7();
	
	if(points == 7)
	{
		std::cout << "You passed all the tests of this exam." << std::endl;
	}
	else
	{
		std::cout << "You only passed " << points << " of the tests in this exam." << std::endl;
	}
	return EXIT_SUCCESS;
}
