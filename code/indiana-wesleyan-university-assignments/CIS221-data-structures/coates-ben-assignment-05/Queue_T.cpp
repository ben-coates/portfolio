// File: Queue_T.cpp
//
// Author: Benjamin Coates and Aaron Cawthorne
// Course: CIS-221
// Assignment: Lab 5: Queue
//
// Purpose: Implementation file for templatized queue class.
// This file includes method implementations for a Queue.

#ifndef QUEUE_T_CPP
#define QUEUE_T_CPP

#include "Queue_T.h"


/*****************************************************************************
 * Queue Method Implementations
 *****************************************************************************/
// Constructor.
// Postcondition: The queue has been initialized as an empty queue.
template <class T>
Queue<T>::Queue ()
// Initialization of data members
:data_(new element_type[DEFAULT_CAPACITY]), first_(0), last_(0), count_(0), capacity_(DEFAULT_CAPACITY)
{
	// No Code Needed
}

// Copy constructor.
// Postcondition: The queue has been initialized with the queue argument
//  passed in (i.e., same values, order, and number of elements).
template <class T>
Queue<T>::Queue (const Queue<T> &rhs)
// Initialization of data memmbers
:data_(new element_type[DEFAULT_CAPACITY]), first_(rhs.first_), last_(rhs.last_), count_(rhs.count_), capacity_(rhs.capacity_)
{
	// Copies data from queue passed in to new queue
	std::copy(rhs.data_, rhs.data_ + capacity_, data_);
}

// Destructor
// Postcondition: Any allocated memory has been reclaimed/freed.
template <class T>
Queue<T>::~Queue (void)
{
	// Deletes the data from the queue
	delete [] data_;
}

// Assignment operator.
// Postcondition: The queue has been assigned the queue argument
//  passed in (i.e., same values, order, and number of elements).
template <class T>
Queue<T> &
Queue<T>::operator= (const Queue<T> &rhs)
{
	// Handles the case of self-assignment.
	if(this == &rhs)
	{
		return *this;
	}
	// Handles the case where capacities are not equal
	if(capacity_ != rhs.capacity_)
	{
		element_type *new_data;							// Declares new pointer to array
		new_data = new element_type[rhs.capacity_];				// Sets the new pointer equal to a new array
		delete [] data_;							// Deletes the old data pointer
		this->data_ = new_data;							// Sets the new data pointer equal to the new array
		this->capacity_ = rhs.capacity_;					// Sets the new capacity equal to the capacity passed in
	}
	this->first_ = rhs.first_;							// Sets the new first equal to the first passed in
	this->last_ = rhs.last_;							// Sets the new last equal to the first passed in
	this->count_ = rhs.count_;							// Sets the new count equal to the count passed in
	std::copy(rhs.data_, rhs.data_ + capacity_, data_);				// Copies the data passed in to the new data
	return *this;									// returns the new Queue
}

// Postcondition: A new copy of <new_item> is at the back of the queue.
template <class T>
void
Queue<T>::enqueue (const T &new_item)
{
	// Handles the case of the Queue being empty
	if (size() == 0)
	{
		data_[0] = new_item;							// Sets the data in index 0 to the new item
		++count_;								// Adds one to count
	}
	
	// Handles the case of the Queue not being full
	else if(size() < capacity_ -1)
	{
		last_ = next_index(last_);						// Sets last equal to the index after it
		data_[last_] = new_item;						// Sets the data in the index of last equal to the new item
		++count_;								// Adds one to count
	}
	// Handles the case of the Queue being full
	else
	{
		size_t new_capacity = capacity_ * 2;					// Creates a variable for the new capacity and sets it equal to twice the old capacity
		element_type *new_data;							// Declares new pointer to array
		new_data = new element_type[new_capacity];				// Sets the new pointer equal to a new array
		size_t j = 0;								// Declares an iterator
		// For loop that sets the data in the new array equal to the data in the old array.
		for(size_t i = first_; i <= last_; ++i)
		{
			if(i == capacity_)
			{
				i = 0;
			}
			new_data[j] = data_[i];
			++j;
		}
		delete [] data_;							// Deletes the old data
		data_ = new_data;							// Points the data pointer at the new data
		capacity_ = new_capacity;						// sets capacity equal to the new capacity
		first_ = 0;								// sets first equal to index 0
		last_ = j;								// sets last equal to j, which is the last index
		data_[last_] = new_item;						// sets the data in index last equal to new item
		++count_;								// Adds one to count
	}
}

// Precondition: size() > 0.
// Postcondition: The front item on the queue has been removed.
//   Throws the <Underflow> exception if the queue is empty.
template <class T>
void
Queue<T>::dequeue (void)
{
	// Hanldes the case of an item being in the Queue
	if(size() > 0)
	{
		first_ = next_index(first_);						// Sets the first index to the index after the first
		--count_;								// Subtracts one from count
	}
	// Handles the case of no items in the Queue
	else
	{
		throw Underflow();
	}
}

// Precondition: size() > 0.
// Postcondition: Returns the first queue item.
//   Throws the <Underflow> exception if the queue is empty.
template <class T>
T
Queue<T>::first (void) const
{
	// Handles the case of an item being in the Queue
	if(size() > 0)
	{
		return data_[first_];							// Returns the item in the first index
	}
	// Handles the case of no items in the Queue
	else
	{
		throw Underflow();
	}
}

// Postcondition: Returns true if the queue is empty, false otherwise.
template <class T>
bool
Queue<T>::is_empty (void) const
{
	return(size() > 0);								// Returns true if the size is greater than zero
}

// Postcondition: Returns the current number of elements in the queue.
template <class T>
size_t
Queue<T>::size (void) const
{
	return count_;									// Returns the number of items in the Queue
}

// Postcondition: Returns true if the
//   size()'s of the two queues are equal and all the elements from 0
//   .. size()-1 are equal, else false.
template <class T>
bool
Queue<T>::operator== (const Queue<T> &rhs) const
{
	// Handles the case of both Queues being empty
	if(size() == 0 && rhs.size() == 0)
	{
		return true;
	}
	// Handles the case of Queue sizes being equal
	else if(size() == rhs.size())
	{
		// Checks to makes sure all the data in the indexes are equal
		size_t j = this->first_;
		for(size_t i = rhs.first_; i != rhs.last_; ++i)
		{
			if(i == capacity_)
			{
				i = 0;
			}
			if(this->data_[j] != rhs.data_[i])
			{
				return false;
			}
			++j;
			if(j == capacity_)
			{
				j = 0;
			}
			
		}
		return true;
	}
	// Handles the case where sizes are not equal
	else
	{
		return false;
	}
}

// Postcondition: Returns false if the
//   size()'s of the two queues are equal and all the elements from 0
//   .. size()-1 are equal, else true.
template <class T>
bool
Queue<T>::operator!= (const Queue<T> &rhs) const
{
	return!(this == &rhs);								// Returns the oppisite bool of the == operator
}

// Precondition: The parameter passed in is a valid index into the data
//  array.
// Postcondition: Returns the next index to use in the array.
template <class T>
size_t
Queue<T>::next_index (size_t index)
{
	// Makes sure that the index is valid
	assert (index < capacity_);
	// Handles the case where index is not last index
	if(index < capacity_ - 1)
	{
		return index + 1;
	}
	// Handles case where index is last index
	else
	{
		return index = 0;
	}
}

#endif /* QUEUE_T_CPP */