// Provided by:   ____________Benjamin Coates & Aaron Cawthorne__________
// Lab:           ____________Lab #2: Sequence________
// Course number: ____________CIS-221-A________
// FILE: sequence.cpp
// CLASS PROVIDED: sequence (part of the namespace main_savitch_4)
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the List
//   If there is insufficient dynamic memory, then the following functions
//   throw a BAD_ALLOC exception: The constructors, insert, attach.

#include <algorithm>
#include <cassert>
#include "sequence.h"


namespace main_savitch_4
{
  // CONSTRUCTOR
  // Postcondition: The sequence has been initialized as an empty sequence.
  // The insert/attach functions will work efficiently (without allocating
  // new memory) until this capacity is reached.
    
  sequence::sequence(size_type initial_capacity)
  {
    data_ = new value_type[initial_capacity];
    capacity_ = initial_capacity;
    used_ = 0;
  }
  
  // COPY CONSTRUCTOR
  // Postcondition: The sequence has been initialized to the sequence
  //   passed in.
  // The insert/attach functions will work efficiently (without allocating
  // new memory) until the source's capacity is reached.
  sequence::sequence(const sequence& source)
  {
    data_ = new value_type[source.capacity_];
    std::copy(source.data_, source.data_ + source.used_, data_);
    capacity_ = source.capacity_;
    used_ = source.used_;
    current_index_ = source.current_index_;
  }
    
  // DESTRUCTOR
  // Postcondition: The memory allocated for the object has been released.
  sequence::~sequence( )
  {
    delete [] data_;
  }
    
  // MODIFICATION MEMBER FUNCTIONS
    
  // Postcondition: The sequence's current capacity is changed to the
  //   new_capacity (but not less than the number of items already on the
  //   list). The insert/attach functions will work efficiently (without
  //   allocating new memory) until this new capacity is reached.
  void sequence::resize(size_type new_capacity)
  {
    value_type *larger_sequence;
	  
    // Checks to see if the new capacity is valid
    // If it is, returns nothing and capacity stays the same
    // If it isn't, resizes the capacity to equal the used space
    if(new_capacity == capacity_)
      {
	return;
      }
    if (new_capacity < used_)
      {
	new_capacity = used_;
      }
	  
    // Copies the data into the larger sequence
    larger_sequence = new value_type[new_capacity];
    std::copy(data_, data_ + used_, larger_sequence);
    delete[]data_;
    data_ = larger_sequence;
    capacity_ = new_capacity;
  }
    
  // Postcondition: The first item on the sequence becomes the current item
  //   (but if the sequence is empty, then there is no current item).
  void sequence::start( )
  {
    current_index_ = 0;
  }
		
  // Precondition: is_item returns true.
  // Postcondition: If the current item was already the last item in the
  //   sequence, then there is no longer any current item. Otherwise, the new
  //   current item is the item immediately after the original current item.
  void sequence::advance( )
  {
    assert(is_item());
    ++current_index_;
  }
    
  // Postcondition: A new copy of entry has been inserted in the sequence
  //   before the current item. If there was no current item, then the new
  //   entry has been inserted at the front of the sequence. In either case,
  //   the newly inserted item is now the current item of the sequence.
  void sequence::insert(const value_type& entry)
  {
    if (is_item())
      {
	move_down(current_index_);
	data_[current_index_] = entry;
	++used_;
      }
    else
      {
	move_down(0);
	data_[0] = entry;
	current_index_ = 0;
	++used_;
      }
  }
    
  // Postcondition: A new copy of entry has been inserted in the sequence
  //   after the current item. If there was no current item, then the new
  //   entry has been attached to the end of the sequence. In either case,
  //   the newly inserted item is now the current item of the sequence.
  void sequence::attach(const value_type& entry)
  {
    if (!is_item())
      {
	current_index_ = used_;
	data_[current_index_] = entry;
	++used_;
      }
    else
      {
	move_down(current_index_);
	data_[current_index_ + 1] = entry;
	++current_index_;
	++used_;
      }
  }
    
  // Precondition: is_item returns true.
  // Postcondition: The current item has been removed from the sequence,
  //   and the item after this (if there is one) is now the new current item.
  void sequence::remove_current( )
  {
    assert(is_item());
    move_up(current_index_);
  }
    
  // Postcondition: The current object is equivalent to the object passed
  //   in.
  void sequence::operator =(const sequence& source)
  {
    // Checks to see if capacities of both sequences are not equal.
    // If they are unequal sets the capacities to equal.
    if(capacity_ != source.capacity_)
      {
	value_type*New_data_;
	New_data_ = new value_type[source.capacity_];
	delete [] data_;
	data_ = New_data_;
	capacity_ = source.capacity_;
      }
	
    // Sets the used and current index to equal the source
    // Copies the data from source sequence into the other sequence
    used_ = source.used_;
    current_index_ = source.current_index_;
    std::copy(source.data_, source.data_ + used_, data_);
  }
    
  // CONSTANT MEMBER FUNCTIONS
    
  // Postcondition: The return value is the number of items in the sequence.
  sequence::size_type sequence::size( ) const
  {
    return used_;
  }
    
  // Postcondition: A true return value indicates that there is a valid
  //   "current" item that may be retrieved by activating the current
  //   member function (listed below). A false return value indicates that
  //   there is no valid current item.
  bool sequence::is_item( ) const
  {
    return (current_index_ < used_);
  }
    
  //  Precondition: is_item( ) returns true.
  //  Postcondition: The item returned is the current item in the sequence.
  sequence::value_type sequence::current( ) const
  {
    assert (is_item());
    return data_[current_index_];
  }
    
  //  Postcondition: The return value is true if both sequences contain no
  //    data items. Also, if the length is greater than zero, then the
  //    sequences must contain the same number of items and the items at the
  //    same location must be equal.
  bool sequence::operator ==(const sequence& other)
  {
    // Checks to see if both sequences are empty. If they are returns true.
    if(used_ == 0 && other.used_ == 0)
      {
	return true;
      }
	  
    // Checks to see if both sequences have the same amount of used space.
    // If they do, checks to see if the data in each location is the same.
    // If they are identical sequences, returns true.
    // If they are not identical sequences, returns false.
    else if(used_ == other.used_)
      {
	bool value;
	for(size_type i = 0; i < used_; ++i)
	  {
	    if(data_[i] == other.data_[i])
	      {
		value = true;
	      }
	    else
	      {
		value = false;
	      }
	  }
	return value;
      }
    else
      {
	return false;
      }
  }
    
  //  Postcondition: Th e return value is false if both sequences contain no
  //    data items. Also, if the length is greater than zero, then the
  //    sequences must not contain the same number of items or the items at
  //    the same location must not be equal.
  bool sequence::operator !=(const sequence& other)
  {
    return(!(*this==other));
  }
    
  // HELPER (PRIVATE) FUNCTIONS
    
  // Precondition: The capacity is (at least one) bigger than the number of
  //   items stored.
  // Postcondition: All data items from index to the number of items stored
  //   will be moved down one space.
  void sequence::move_down(size_type index)
  {
    // Checks to see if there is room in the sequence to move the items down
    // If there is, moves the items down one
    // If there is not, resizes the sequence by one, and then moves the items down one.
    if (used_ < capacity_)
      { 
	for(size_type i = used_; i > index; --i)
	  {
	    data_[i] = data_[i-1];
	  }
      }
    else
      { 
	resize(capacity_ +1);
	for(size_type i = used_; i > index; --i)
	  {
	    data_[i] = data_[i-1];
	  }
      }	
  }
    
  // Precondition: There is at least one item stored.
  // Postcondition: All data items from index to the number of items stored
  //   will be moved up one space.
  void sequence::move_up(size_type index)
  {
    assert(is_item());
    for(size_type i = index; i < used_; ++i)
      {
	data_[i] = data_[i+1];
      }
    used_ = used_ - 1;
  }
}
