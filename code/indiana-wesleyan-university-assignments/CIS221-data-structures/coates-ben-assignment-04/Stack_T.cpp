// File: Stack_T.cpp
//
// Author: Benjamin Coates and Aaron Cawthrorne
// Course: CIS 221 - Data Structures
// Assignment: Lab 4 - Stack
//
// Purpose: Implementation file for templatized stack class.
// This class is being constructed to provide more flexibility
// (over an array) in the data structures we want.
// This file includes method implementations for a Stack and Link_Node.

#ifndef STACK_T_TEMPLATE
#define STACK_T_TEMPLATE

#include "Stack_T.h"


//*****************************************************************************
//* Link_Node Method Implementations
//*****************************************************************************
template <class T>
Link_Node<T>::Link_Node (const T &item, Link_Node<T> *next)
:item_(item), next_(next)
{
	assert(next_ == NULL);
	next_ = this;
}

template <class T>
Link_Node<T>::Link_Node (void)
{
	next_ = this;
}

/*****************************************************************************
 * Stack Method Implementations
 *****************************************************************************/
// Constructor.
// Postcondition: The stack has been initialized as an empty stack.
// Allocates Memory
template <class T>
Stack<T>::Stack ()
:tail_(new Link_Node<T>), count_(0)
{
	// No code needed tail and count already initialized.
}

// Copy constructor.
// Postcondition: The stack has been initialized with the stack argument
// passed in (i.e., same values, order, and number of elements).
// Alocates Memory
template <class T>
Stack<T>::Stack (const Stack<T> &rhs)
:count_(rhs.count_)
{
	copy_list(tail_, rhs);
}

// Destructor
// Postcondition: Any allocated memory has been reclaimed/freed.
// Deallocates memory
template <class T>
Stack<T>::~Stack (void)
{
	delete_list(tail_);
}

// Postcondition: The start_node will contain a copy of the linked list in
// the rhs argument. This can throw a std::bad_alloc exception.
template <class T>
void
Stack<T>::copy_list (Link_Node<T> *&start_node, const Stack<T> &rhs)
{
	
	start_node = new Link_Node<T>;					// Initializes a new node called start_node
	Link_Node<T>* prev_node = start_node;			// Initializes a new node pointer called prev_node points it at the start_node
	for(Link_Node<T>* cursor_ = rhs.tail_->next_; cursor_ != rhs.tail_; cursor_ = cursor_->next_)
	{
		Link_Node<T>* new_node = new Link_Node<T>;	// Initializes a new node pointer called new_node and points it at a new node
		new_node->next_ = start_node;				// Makes the new node point to the start_node
		prev_node->next_ = new_node;				// Makes the node that prev_node points to, point to the new_node
		prev_node = new_node;						// Points the prev_node pointer to the new_node
		new_node->item_ = cursor_->item_;			// Sets the item in the new node equal to the item that the cursor points to
	}
	this->count_ = rhs.count_;						// Sets the count of the new list to equal that of the list being copied
}

// Postcondition: The memory from the linked list pointed to be start_node is
// reclaimed/freed.
template <class T>
void
Stack<T>::delete_list (Link_Node<T> *start_node)
{
	while(start_node->next_ != start_node)			// While loop continues until start_node->next == start_node
	{
		Link_Node<T>* cursor_ = start_node->next_;	// Initializes a new node pointer called cursor and points it at the node after start_node
		start_node->next_ = cursor_->next_;			// Sets the node that start_node points to as the node after the node cursor points to
		delete cursor_;								// Deletes the item node pointer cursor and the item it points to
	}
	delete start_node;								// Deletes the last node start_node after the while loop has finished.
}

// Assignment operator.
// Postcondition: The stack has been assigned the stack argument
//  passed in (i.e., same values, order, and number of elements).
template <class T>
Stack<T> &
Stack<T>::operator= (const Stack<T> &rhs)
{
	Link_Node<T>* temp_ptr = this->tail_;			// Initializes a new node pointer that points to the tail_ of the stack passed in
	copy_list(tail_, rhs);							// Uses the copy list function to copy the stack passed in the arguement
	delete_list(temp_ptr);							// Deletes the pointer initalized at the beginning
	return *this;									// Returns a copy of the stack to the stack being assigned
}

// Postcondition: Returns the current number of elements in the stack.
template <class T>
size_t
Stack<T>::size (void) const
{
	return count_;
}

// Postcondition: Returns true if the
//   size()'s of the two stacks are equal and all the elements from 0
//   .. size()-1 are equal, else false.
template <class T>
bool
Stack<T>::operator== (const Stack<T> &rhs) const
{
	if(size () == 0 && rhs.size () == 0)			// Tests to see if both stacks are empty
	{
		return true;
	}
	if(size () == rhs.size ())						// Tests to see if stack's sizes are equal
	{
		Link_Node<T> *cursor_;						// Initializes a node pointer
		Link_Node<T> *rhs_cursor_;					// Initializes another node pointer
		rhs_cursor_ = rhs.tail_->next_;				// Makes rhs_cursor point to the node after rhs.tail_
		for(cursor_ = tail_->next_; cursor_ != tail_; cursor_ = cursor_->next_)
		{
			if(cursor_->item_ != rhs_cursor_->item_)	// Checks to see of the items are not equal
			{
				return false;
			}
			rhs_cursor_ = rhs_cursor_->next_;		// moves the cursor of the second stack
		}
		return true;
	}
	else
	{
		return false;
	}
}

// Postcondition: Returns false if the
//   size()'s of the two stacks are equal and all the elements from 0
//   .. size()-1 are equal, else true.
template <class T>
bool
Stack<T>::operator!= (const Stack<T> &rhs) const
{
	if(size () == 0 && rhs.size () == 0)			// See comments for equality operator
	{
		return false;
	}
	if(size () == rhs.size ())
	{
		Link_Node<T> *cursor_;
		Link_Node<T> *rhs_cursor_;
		rhs_cursor_ = rhs.tail_->next_;
		for(cursor_ = tail_->next_; cursor_ != tail_; cursor_ = cursor_->next_)
		{
			if(cursor_->item_ != rhs_cursor_->item_)
			{
				return true;
			}
			rhs_cursor_ = rhs_cursor_->next_;
		}
		return false;
	}
	else
	{
		return true;
	}
}

// Postcondition: A new copy of <new_item> is at the top of the stack.
template <class T>
void
Stack<T>::push (const T &new_item)
{
	Link_Node<T>* new_node = new Link_Node<T>;		// Initializes a node pointr and points it at a new node
	new_node->item_ = new_item;						// Sets the item of the new node as the item passed in
	new_node->next_ = this->tail_->next_;			// Points node after the new_node at the node after the tail_ node
	this->tail_->next_ = new_node;					// Sets the item the tail_ node points to as the new_node
	++count_;										// Increments count
}

// Precondition: size() > 0.
// Postcondition: The top item on the stack has been removed.
//   Throws the <Underflow> exception if the stack is empty.
template <class T>
void
Stack<T>::pop (void)
{
	if(size() > 0)
	{
		Link_Node<T>* temp_ptr;						// Initializes a node pointer
		temp_ptr = this->tail_->next_;				// Points temp_ptr at the first item on the stack
		this->tail_->next_ = temp_ptr->next_;		// Points the tail at the second item on the stack
		delete temp_ptr;							// Delets the temp_ptr and the first item on the stack
		--count_;									// decrements the count
	}
	else
	{
		throw Underflow();							// Throws Underflow exception if there are no items on the stack
	}
}

// Precondition: size() > 0.
// Postcondition: Returns the top stack item.
//   Throws the <Underflow> exception if the stack is empty.
template <class T>
T
Stack<T>::top (void) const
{
	if(size() > 0)
	{
		return tail_->next_->item_;					// returns the first item on the stack
	}
	else
	{
		throw Underflow();							// Throws Underflow exception is there are no items on the stack
	}
}

// Postcondition: Returns true if the stack is empty, false otherwise.
template <class T>
bool
Stack<T>::is_empty (void) const
{
	if(size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

#endif /* STACK_T_TEMPLATE */