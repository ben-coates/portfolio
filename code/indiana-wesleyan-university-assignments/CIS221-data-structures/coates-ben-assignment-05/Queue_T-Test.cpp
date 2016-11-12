// File: Queue_T-Test.cpp
//
// Author: Benjamin Coates and Aaron Cawthorn
// Course: CIS-221
// Assignment: Lab 5: Queue
//
// Purpose: Testing file for templatized queue class.

// Standard headers
#include <iostream>
#include <cassert>
#include "Queue_T.h"

// This typedef is useful if you want to queue characters.
typedef Queue<char> CQUEUE;

// Declares a integer to hold the number of points earned and test taken
int points = 0;
int test = 0;

// **************************************************************************
// Function that adds one to the points integer and prints the end of test message.
// **************************************************************************
void test_end()
{
	std::cout << "All tests passed for this Test!" << std::endl;
	++points;
	std::cout << "So far, you have passed " << points << " of " << test <<" tests possible." << std::endl << std::endl << std::endl;
}

// **************************************************************************
// Function that prints out a test failed message.
// **************************************************************************
void test_fail()
{
	std::cout << "TEST FAILED!!!" << std::endl << std::endl;
}

// **************************************************************************
// Precondition: Arguement is a CQUEUE
// Postcondition: Function returns true if underflow is thrown.
// Returns false if it is not thrown.
// **************************************************************************
bool underflow_test(CQUEUE queue)
{
	try
	{
		queue.dequeue();
	}
	catch (Queue<char>::Underflow)
	{
		std::cout << "Underflow Thrown." << std::endl;
		return true;
	}
	return false;
}

// **************************************************************************
// Precondition: Arguements are a QUEUE, char, and int.
// Postcondition: Function returns true if verification is met
// Returns false if it is not.
// **************************************************************************
bool first_item_verification(CQUEUE queue, char let, size_t num)
{
	if(queue.first() != let)
	{
		test_fail();
		return false;
		return 0;
	}
	if(queue.size() != num)
	{
		test_fail();
		return false;
		return 0;
	}
	return true;
}

// **************************************************************************
// Test 1: Tests dequeuing an element from an empty queue and making sure that underflow is thrown.
// **************************************************************************
int test1()
{
	++test;
	std::cout << std::endl; // Formatting line: Adds a blank line at first of output
	std::cout << "BEGINNING TEST 1:" << std::endl;
	std::cout << "Testing to see that underflow is thrown correctly." << std::endl;
	
	// Declares a queue
	std::cout << "Creating a queue called A_queue." << std::endl;
	CQUEUE A_queue;
	
	// Tests to see that underflow is thrown
	std::cout << "Testing to see that underflow is thrown on a queue with no items in it." << std::endl;
	if (underflow_test(A_queue) != true)
	{
		test_fail();
		return 0;
	}
	
	// Adds an item to the queue
	A_queue.enqueue('a');
	
	// Tests to make sure that underflow is not thrown on a queue with an item in it.
	std::cout << "Testing to see that underflow is not thrown on a queue with items in it." << std::endl;
	if (underflow_test(A_queue) != false)
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
	++test;
	std::cout << "BEGINNING TEST 2:" << std::endl;
	std::cout << "Testing to see that the copy constucor works correctly." << std::endl;
	
	// Declares a queue
	std::cout << "Creating a queue called A_queue." << std::endl;
	CQUEUE A_queue;
	
	// Adds characters 'a', 'b', and 'c' to A_queue and verfies them while adding
	std::cout << "Adding the characters 'a', 'b', and 'c' to A_queue." << std::endl;
	std::cout << "Checking to make sure they are correct as they are added." << std::endl;
	
	// Adds character 'a' to A_queue and checks size
	std::cout << "Adding 'a' to A_queue." <<std::endl;
	A_queue.enqueue('a');
	std::cout << "Using the first function to check that 'a' has been added to the A_queue and that checking size equals 1." <<std::endl;
	if(first_item_verification(A_queue, 'a', 1) != true)
	{
		return 0;
	}
	std::cout << "'" <<A_queue.first() << "' has been added to the A_queue." << std::endl;
	
	// Adds character 'b' to A_queue  and checks size
	std::cout << "Adding 'b' to A_queue." <<std::endl;
	A_queue.enqueue('b');
	std::cout << "Using the first function to check that 'b' has been added to the A_queue and checking that size equals 2." <<std::endl;
	if(first_item_verification(A_queue, 'a', 2) != true)
	{
		return 0;
	}
	std::cout << "'" << A_queue.first() << "' has been added to the A_queue." << std::endl;
	
	// Adds character 'c' to A_queue and checks size
	std::cout << "Adding 'c' to A_queue." <<std::endl;
	A_queue.enqueue('c');
	std::cout << "Using the first function to check that 'c' has been added to the A_queue and checking that size equals 3." <<std::endl;
	if(first_item_verification(A_queue, 'a', 3) != true)
	{
		return 0;
	}
	std::cout << "'" << A_queue.first() <<"' has been added to the A_queue." << std::endl;
	
	// Declares and copies A_queue into a new CQUEUE called B_queue
	std::cout << "Making a copy of A_queue called B_queue, and then checking to make sure it is correct" << std::endl;
	CQUEUE B_queue(A_queue);
	
	// Loop that checks to make sure all items in B_queue, match A_queue
	std::cout << "Checking to makes sure B_queue is a correct copy of A_queue" << std::endl;
	while(B_queue.size() > 0)
	{
		if(first_item_verification(B_queue, A_queue.first(), A_queue.size()) != true)
		{
			return 0;
		}
		A_queue.dequeue();
		B_queue.dequeue();
	}
	std::cout << "B_queue was a corect copy of A_queue" << std::endl << std::endl;
	
	// Performs and overflow test on A_queue and B_queue
	std::cout << "Testing to make sure that A_queue and B_queue are both empty." << std::endl;
	if(underflow_test(A_queue) != true)
	{
		test_fail();
		return 0;
	}
	if(underflow_test(B_queue) != true)
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
	++test;
	std::cout << "BEGINNING TEST 3:" << std::endl;
	std::cout << "Testing the equality and inequality operators." << std::endl;
	
	// Declares six queues for testing
	std::cout << "Creating six queues A_queue,B_queue ,C_queue, D_queue, E_queue & F_queue" << std::endl << std::endl;
	CQUEUE A_queue, B_queue, C_queue, D_queue, E_queue, F_queue;
	
	// Enqueues three characters onto A_queue
	std::cout << "Enqueuing 'a', 'b', and 'c' onto A_queue" << std::endl;
	A_queue.enqueue('a');
	A_queue.enqueue('b');
	A_queue.enqueue('c');
	
	// Enqueues three characters onto B_queue
	std::cout << "Enqueuing 'a', 'b', and 'c' onto B_queue" << std::endl;
	B_queue.enqueue('a');
	B_queue.enqueue('b');
	B_queue.enqueue('c');
	
	// Enqueues three characters onto C_queue
	std::cout << "Enqueuing 'e', 'f', and 'g' onto C_queue" << std::endl;
	C_queue.enqueue('e');
	C_queue.enqueue('f');
	C_queue.enqueue('g');
	
	// Enqueues four characters onto D_queue
	std::cout << "Enqueuing 'a', 'b', 'c' and 'd' onto D_queue" << std::endl;
	D_queue.enqueue('a');
	D_queue.enqueue('b');
	D_queue.enqueue('c');
	D_queue.enqueue('d');
	
	// Output message to alert user that there are two empty queues
	std::cout << "E_queue is empty" << std::endl;
	std::cout << "F_queue is empty" << std::endl << std::endl;
	
	// Tests two queues that are empty for equality
	std::cout << "Testing to see if two empty queues are equal." << std::endl;
	std::cout << "Testing to see if E_queue is equal to F_queue!" << std::endl;
	if (E_queue!=(E_queue))
	{
		test_fail();
		return 0;
	}
	std::cout << "E_queue is equal to F_queue...Passed" << std::endl;
	
	// Tests two queues that are equal
	std::cout << "Testing to see if equal queues are equal." << std::endl;
	std::cout << "Testing to see if A_queue is equal to B_queue!" << std::endl;
	if (!(A_queue==(B_queue)))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue is equal to B_queue...Passed" << std::endl;
	
	// Tests two queues that have the same number of items but are not equal
	std::cout << "Testing to see if two queues with the same amount of items are not equal." << std::endl;
	std::cout << "Testing to see if A_queue is equal to C_queue!" << std::endl;
	if (A_queue==(C_queue))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue is not equal to C_queue...Passed" << std::endl;
	
	// Tests two queues that have different number of items but the same items in the first 3 spots.
	std::cout << "Testing to see if two queues with different amounts of items," << std::endl;
	std::cout << "but the same items in the first three spots the are not equal." << std::endl;
	std::cout << "Testing to see if A_queue is equal to D_queue!" << std::endl;
	if (A_queue==(D_queue))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue is not equal to D_queue!...Passed" << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 4: Tests the assignment operator
// **************************************************************************
int test4()
{
	++test;
	std::cout << "BEGINNING TEST 4:" << std::endl;
	std::cout << "Testing the assignment operator." << std::endl;
	
	// Declares two queues A_queue, B_queue, and C_queue.
	std::cout << "Creating three queues called A_queue, B_queue, and C_queue." << std::endl;
	CQUEUE A_queue;
	CQUEUE B_queue;
	CQUEUE C_queue;
	
	// Adds three characters to A_queue
	std::cout << "Adding three characters: 's', 't', and 'u' to A_queue." << std::endl;
	A_queue.enqueue('s');
	A_queue.enqueue('t');
	A_queue.enqueue('u');
	
	// Checks to make sure A_queue has three characters in it
	std::cout << "Checking to makes sure A_queue has three character in it." << std::endl;
	if(A_queue.size() != 3)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue has three character in it." << std::endl;
	
	// Tests to make sure that A_queue and C_queue are not the same
	std::cout << "C_queue is an empty queue. Testing to make sure A_queue and C_queue are not the same." <<std::endl;
	if(A_queue==(C_queue))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue and C_queue are not the same." << std::endl << std::endl;
	
	// Uses the assignment operator to make B_queue equal to A_queue
	// and tests to make sure that A_queue and B_queue are equal.
	std::cout << "Assigning B_queue to equal A_queue." << std::endl;
	B_queue=(A_queue);
	std::cout << "Testing to make sure A_queue and B_queue are the same." <<std::endl;
	if(!(B_queue==(A_queue)))
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue and B_queue are equal." << std::endl << std::endl;
	
	// Uses the assignment operator to make A_queue equal C_queue, which is an empty queue;
	// And test to make sure that A_queue and C_queue are equal.
	std::cout << "Assinging A_queue to equal C_queue, which is still empty." << std::endl;
	A_queue=(C_queue);
	std::cout << "Testing to make sure A_queue and C_queue are the same." <<std::endl;
	if(!(A_queue==(C_queue)))
	{
		test_fail();
		return 0;
	}
	std:: cout << "A_queue and C_queue are equal." << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 5: Test dequeuing all elements until we get an Underflow exception.
// **************************************************************************
int test5()
{
	++test;
	std::cout << "BEGINNING TEST 5:" << std::endl;
	std::cout << "Testing dequeueing of  all elements until we get an Underflow exception." << std::endl;
	std::cout << "Testing firsting on an empty queue and makes sure that Underflow is thrown." <<std::endl;
	std::cout << "Adding three characters to a queue and dequeuing all items until underflow is thrown" << std::endl;
	
	// Declares a queue
	std::cout << "Creating a queue called A_queue." << std::endl;
	CQUEUE A_queue;
	
	// Adds three characters to the queue
	std::cout << "Adding 'a', 'b', and 'c' to A_queue." << std::endl;
	A_queue.enqueue('a');
	A_queue.enqueue('b');
	A_queue.enqueue('c');
	
	// dequeues the elements off the queue until underflow is thrown, then catches the exception.
	std::cout << "dequeueing the elements of the queue so that underflow is thrown." << std::endl;
	while (A_queue.size() > 0)
	{
		A_queue.dequeue();
	}
	if (underflow_test(A_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "Underflow thrown correctly." << std::endl << std::endl;
	
	// Uses the first function to elict an Underflow exception
	std::cout << "Testing that using the first function on A_queue throws the underflow exception" << std::endl;
	int answer = 0;
	try
	{
		A_queue.first();
	}
	catch (Queue<char>::Underflow)
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
	++test;
	std::cout << "BEGINNING TEST 6:" << std::endl;
	std::cout << "Testing to make sure the is_empty function works correctly." << std::endl;
	
	// Declares queues
	std::cout << "Creating two queues called A_queue and B_queue." << std::endl;
	CQUEUE A_queue;
	CQUEUE B_queue;
	
	// Adds a character to A_queue and test to make sure it is not empty
	std::cout << "Adding chracter to A_queue so that it not longer empty" << std::endl;
	A_queue.enqueue('a');
	std::cout << "Testing to see that A_queue is not empty." << std::endl;
	if (A_queue.is_empty() != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue is not empty." << std::endl << std::endl;
	
	// Tests to make sure that B_queue is empty
	std::cout << "Testing to see that B_queue is empty." << std::endl;
	if (B_queue.is_empty() != false)
	{
		test_fail();
		return 0;
	}
	std::cout << "B_queue is empty." << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}


// **************************************************************************
// Test 7: Tests the enqueuing, dequeuing and firsting of items extensively
// **************************************************************************
int test7()
{
	++test;
	std::cout << "BEGINNING TEST 7:" << std::endl;
	std::cout << "Testing the enqueuing, dequeuing, and firsting of character on a queue." << std::endl;
	
	// Declares four queues
	std::cout << "Creating six queues A_queue, B_queue, C_queue, and D_queue." << std::endl << std::endl;
	CQUEUE A_queue, B_queue, C_queue, D_queue, E_queue, F_queue;
	
	// Enqueues three characters onto A_queue
	std::cout << "Enqueuing 'a', 'b', and 'c' onto A_queue" << std::endl;
	A_queue.enqueue('a');
	A_queue.enqueue('b');
	A_queue.enqueue('c');
	
	// Enqueues three characters onto B_queue
	std::cout << "Enqueuing 'a', 'b', and 'c' onto B_queue" << std::endl;
	B_queue.enqueue('a');
	B_queue.enqueue('b');
	B_queue.enqueue('c');
	
	// Enqueues three characters onto C_queue
	std::cout << "Enqueuing 'e', 'f', and 'g' onto C_queue" << std::endl;
	C_queue.enqueue('e');
	C_queue.enqueue('f');
	C_queue.enqueue('g');
	
	// Enqueues four characters onto D_queue
	std::cout << "Enqueuing 'a', 'b', 'c' and 'd' onto D_queue" << std::endl;
	D_queue.enqueue('a');
	D_queue.enqueue('b');
	D_queue.enqueue('c');
	D_queue.enqueue('d');
	
	// Uses dequeue and first to check A_queue, and then checks to make sure it is empty.
	std::cout << "Using first and dequeue to check that A_queue is accurate." << std::endl;
	if(first_item_verification(A_queue, 'a', 3) != true)
	{
		return 0;
	}
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'b', 2) != true)
	{
		return 0;
	}
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'c', 1) != true)
	{
		return 0;
	}
	A_queue.dequeue();
	std::cout << "A_queue was correct." << std::endl;
	std::cout << "Checking to make sure A_queue is empty." << std::endl;
	if (underflow_test(A_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue is empty." << std::endl << std::endl;
	
	// Uses dequeue and first to check B_queue, and then checks to make sure it is empty.
	std::cout << "Using first and dequeue to check that B_queue is accurate." << std::endl;
	if(first_item_verification(B_queue, 'a', 3) != true)
	{
		return 0;
	}
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'b', 2) != true)
	{
		return 0;
	}
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'c', 1) != true)
	{
		return 0;
	}
	B_queue.dequeue();
	std::cout << "B_queue was correct." << std::endl;
	std::cout << "Checking to make sure B_queue is empty." << std::endl;
	if (underflow_test(B_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "B_queue is empty." << std::endl << std::endl;
	
	// Uses dequeue and first to check C_queue, and then checks to make sure it is empty.
	std::cout << "Using first and dequeue to check that C_queue is accurate." << std::endl;
	if(first_item_verification(C_queue, 'e', 3) != true)
	{
		return 0;
	}
	C_queue.dequeue();
	if(first_item_verification(C_queue, 'f', 2) != true)
	{
		return 0;
	}
	C_queue.dequeue();
	if(first_item_verification(C_queue, 'g', 1) != true)
	{
		return 0;
	}
	C_queue.dequeue();
	std::cout << "C_queue was correct." << std::endl;
	std::cout << "Checking to make sure C_queue is empty." << std::endl;
	if (underflow_test(C_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "C_queue was empty." << std::endl << std::endl;
	
	// Uses dequeue and first to check D_queue
	std::cout << "Using first and dequeue to check that D_queue is accurate." << std::endl;
	if(first_item_verification(D_queue, 'a', 4) != true)
	{
		return 0;
	}
	D_queue.dequeue();
	if(first_item_verification(D_queue, 'b', 3) != true)
	{
		return 0;
	}
	D_queue.dequeue();
	if(first_item_verification(D_queue, 'c', 2) != true)
	{
		return 0;
	}
	D_queue.dequeue();
	if(first_item_verification(D_queue, 'd', 1) != true)
	{
		return 0;
	}
	D_queue.dequeue();
	std::cout << "D_queue was correct." << std::endl;
	std::cout << "Checking to make sure D_queue is empty." << std::endl;
	if (underflow_test(D_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "D_queue was empty." << std::endl << std::endl;
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

// **************************************************************************
// Test 8: Tests to enqueing of elements onto a full queue
// to make sure that it resizes appropriately
// **************************************************************************
int test8()
{
	++test;
	std::cout << "BEGINNING TEST 8:" << std::endl;
	std::cout << "Testing to make sure that enque resizes the array correctly." << std::endl;
	std::cout << "The default capacity of the array for this queue is 5." << std::endl;
	
	// Declares queues
	std::cout << "Creating two queues called A_queue and B_queue." << std::endl;
	CQUEUE A_queue;
	CQUEUE B_queue;
	
	// Enqueues five characters onto A_queue
	std::cout << "Enqueuing 'a', 'b', 'c', 'd', and 'e' onto A_queue." << std::endl;
	A_queue.enqueue('a');
	A_queue.enqueue('b');
	A_queue.enqueue('c');
	A_queue.enqueue('d');
	A_queue.enqueue('e');
	
	// Checks that size is correct
	std::cout << "Checking that size equals five." << std::endl;
	if (A_queue.size() != 5)
	{
		test_fail();
		return 0;
	}
	std::cout << "Size is correct." << std::endl;
	
	// Adds an additional element to A_queue and test to make sure it resized coreectly
	std::cout << "Adding an addittional character to A_queue and making sure it resizes coreectly." << std::endl;
	A_queue.enqueue('f');
	// Uses dequeue and first to check A_queue
	std::cout << "Using first and dequeue to check that A_queue is accurate." << std::endl;
	if(first_item_verification(A_queue, 'a', 6) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << A_queue.first() << "'" << std::endl;
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'b', 5) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << A_queue.first() << "'" << std::endl;
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'c', 4) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << A_queue.first() << "'" << std::endl;
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'd', 3) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << A_queue.first() << "'" << std::endl;
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'e', 2) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << A_queue.first() << "'" << std::endl;
	A_queue.dequeue();
	if(first_item_verification(A_queue, 'f', 1) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << A_queue.first() << "'" << std::endl;
	A_queue.dequeue();
	std::cout << "A_queue was correct." << std::endl;
	std::cout << "Checking to make sure A_queue is empty." << std::endl;
	if (underflow_test(A_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "A_queue was empty." << std::endl << std::endl;
	
	// Enqueues five characters onto B_queue
	std::cout << "Enqueuing 'a', 'b', 'c', 'd', and 'e' onto B_queue." << std::endl;
	B_queue.enqueue('a');
	B_queue.enqueue('b');
	B_queue.enqueue('c');
	B_queue.enqueue('d');
	B_queue.enqueue('e');
	
	// Checks that size is correct
	std::cout << "Checking that size equals five." << std::endl;
	if (B_queue.size() != 5)
	{
		test_fail();
		return 0;
	}
	std::cout << "Size is correct." << std::endl;
	
	// Takes a characters off and a different on
	std::cout << "Dequeuing a character and enqueuing a different one." << std::endl;
	B_queue.dequeue();
	B_queue.enqueue('f');
	
	// Test to make sure that the assignment and equality operators handles the situation correctly
	std::cout << "Performing brief test on the assignment and equality operators." << std::endl;
	std::cout << "Assigning A_queue to equal B_queue and testing to see that they are equal." << std::endl;
	A_queue=(B_queue);
	if(!(A_queue==(B_queue)))
	{
		test_fail();
		return 0;
	}
	std::cout << "B_queue was a corect copy of A_queue" << std::endl << std::endl;
	std::cout << "They were equal, resuming previous test..." << std::endl << std::endl;
	
	// Adds an additional element to B_queue and test to make sure it resized coreectly
	std::cout << "Adding an addittional character to B_queue and making sure it resizes coreectly." << std::endl << std::endl;
	B_queue.enqueue('g');
	// Uses dequeue and first to check B_queue
	std::cout << "Using first and dequeue to check that B_queue is accurate." << std::endl;
	if(first_item_verification(B_queue, 'b', 6) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << B_queue.first() << "'" << std::endl;
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'c', 5) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << B_queue.first() << "'" << std::endl;
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'd', 4) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << B_queue.first() << "'" << std::endl;
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'e', 3) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << B_queue.first() << "'" << std::endl;
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'f', 2) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << B_queue.first() << "'" << std::endl;
	B_queue.dequeue();
	if(first_item_verification(B_queue, 'g', 1) != true)
	{
		return 0;
	}
	std::cout << "First item was '" << B_queue.first() << "'" << std::endl;
	B_queue.dequeue();
	std::cout << "B_queue was correct." << std::endl;
	std::cout << "Checking to make sure B_queue is empty." << std::endl;
	if (underflow_test(B_queue) != true)
	{
		test_fail();
		return 0;
	}
	std::cout << "B_queue was empty." << std::endl << std::endl;
	
	
	// If code reaches here then all tests have passed
	test_end();
	return points;
}

int main (int argc, char *argv[])
{
	test1(); // Test dequeuing an element from an empty queue.
	
	test2(); // Test the copy constructor.
	
	test3(); // Test the equality and inequality operators
 
	test4(); // Test the assignment operator.
	
	test5(); // Test dequeuing all elements until we get an Underflow exception.
	
	test6(); // Test queues for being empty.
	
	test7(); // Test enqueuing and dequeuing of elements.
	
	test8(); // Test to enqueing of elements onto a full queue to make sure that it resizes appropriately
	
	if(points == 8)
	{
		std::cout << "Congratulations!!! You passed all the tests of this exam!" << std::endl << std::endl;
	}
	else
	{
		std::cout << "You only passed " << points << " of the 8 tests in this exam." << std::endl << std::endl;
	}
	return EXIT_SUCCESS;
}