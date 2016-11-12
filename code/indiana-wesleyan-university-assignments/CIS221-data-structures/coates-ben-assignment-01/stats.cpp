// Provided by:   ____________Benjamin Coates__________
// Lab:           ____________Statistician Lab#1________
// Course number: ____________CIS-221-A________
// FILE: stats.cpp
// CLASS PROVIDED: Statistician
//   (a file to impletment the class stats.h)
//   This class is part of the namespace main_savitch_2C.
//
// VALUE SEMANTICS for the Statistician class:
// Assignments and the copy constructor may be used with Statistician objects.

#include "stats.h"
#include <cassert>

namespace main_savitch_2C
{
    //  Postcondition: The object has been initialized, and is ready to accept
    //  a sequence of numbers. Various statistics will be calculated about the
    //  sequence.
  Statistician::Statistician( )
    {
      reset();
    }

    //  The number r has been given to the Statistician as the next number in
    //  its sequence of numbers.
  void Statistician::next(double r)
    { 
      // If first number sets the number as the tinyest, if check to see if r
      // is smaller than the previous tinyest. If so, sets tinyest  to r.
      if (count_ == 0)
	tinyest_ = r;
      else if (r < tinyest_)
        tinyest_ = r;

      // If first number, sets number as largest, if not checks to see if r 
      // is larfer than largest. If so, sets largest to r.
      if (count_ == 0)
	largest_ = r;
      else if (r > largest_)
        largest_ =r;

      //Adds one to the count evey time next is called
      ++count_ ;

      //Adds the number to the total
      total_  += r;
    }

    //  Postcondition: The Statistician has been cleared, as if no numbers had
    //  yet been given to it.
    void  Statistician::reset( )
    {
      count_ = 0;
      total_ = 0;
      tinyest_ = 0;
      largest_ = 0;
    }

    // CONSTANT MEMBER FUNCTIONS

    //  Postcondition: The return value is the length of the sequence that has
    //  been given to the Statistician (i.e., the number of times that the
    //  next(r) function has been activated).
    int  Statistician::length( ) const
    {
      return count_;
    }

    //  Postcondition: The return value is the sum of all the numbers in the
    //  Statistician's sequence.
    double  Statistician::sum( ) const
    {
      return total_;
    }

    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the arithmetic mean (i.e., the
    //  average of all the numbers in the Statistician's sequence).
    double  Statistician::mean( ) const
    {
		assert(length() > 0);
		  return (total_/count_);
    }
    
    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the tinyest number in the
    //  Statistician's sequence.
    double  Statistician::minimum( ) const
    {
		assert(length() > 0);
		  return tinyest_;
    }
    
    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the largest number in the
    //  Statistician's sequence.
    double  Statistician::maximum( ) const
    {
		assert(length() > 0);
            return largest_;
    }
    
    //  Postcondition: The Statistician that is returned contains all the
    //  numbers of the sequences of s1 and s2.
    Statistician operator + (const Statistician& s1,
                                    const Statistician& s2)
    {
        Statistician s;
        s.count_ = s1.length() + s2.length();
        s.total_ = s1.sum() + s2.sum();
		
		//	When length s1 and s2 are both 0 returns statistician s
		//	without a minimum or maximum.
		if(s1.length() == 0 && s2.length () == 0)
		{
			return s;
		}
		
		//	When s1 length is greater than 0 and s2 length is zero
		//	returns statistician s with s1's minimum and maximum.
		else if(s1.length() > 0 && s2.length() == 0)
		{
			s.tinyest_ = s1.minimum();
			s.largest_ = s1.maximum();
			return s;
		}
		
		//	When s2 length is greater than 0 and s1 length is zero
		//	returns statistician s with s2's minimum and maximum.
		else if(s1.length() == 0 && s2.length() > 0)
		{
			s.tinyest_ = s2.minimum();
			s.largest_ = s2.maximum();
			return s;
		}
		
		//	When s1 and s2 length are both greater than zero
		//	returns statistician s with a minimum of the lowest value
		//	and a maximum of the highest value in s1 and s2.
		else
		{
			if (s1.minimum() < s2.minimum()){
				s.tinyest_ = s1.minimum();
			}
			else
				s.tinyest_ = s2.minimum();
			
			if (s1.maximum() > s2.maximum()){
				s.largest_ = s1.maximum();
			}
            else
				s.largest_ = s2.maximum();
			
			return s;
		}
    }

    //  Postcondition: The Statistician that is returned contains the same
    //  numbers that s does, but each number has been multiplied by the
    //  scale number.
    Statistician operator * (double scale,
			     const Statistician& s)
    {
		//	Creates a Statistician called y
		Statistician y;
		
		//	If the length of Statistician s is 0 returns Statistician y
		if (s.length() == 0)
		{
			return y;
		}
		
		//	If the length of Statistician s is greater than 0 sets
		//	Statistician y equal to (scale * Statistician) and returns
		//	Statistician y
		else
		{
			y.count_ = s.length();
			y.total_ = scale * s.sum();
		
			if (scale < 0){
				y.tinyest_ = scale * s.maximum();
			}
			if (scale >= 0){
				y.tinyest_ = scale * s.minimum();
			}
			if (scale < 0){
				y.largest_ = scale * s.minimum();
			}
			if (scale >= 0){
				y.largest_ = scale * s.maximum();
			}
			return y;
		}
    }

  //  Postcondition: The return value is true if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator ==(const Statistician& s1,
                   const Statistician& s2)
  {
      if (s1.length() == 0 && s2.length() == 0){
          return true;
	  }
      else if (s1.length() == s2.length() && s1.sum() == s2.sum() &&
			   s1.mean() == s2.mean() && s1.minimum() == s2.minimum() &&
			   s1.maximum() == s2.maximum()){
          return true;
	  }
	  else return false;
  }

  //  Postcondition: The return value is false if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  not have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator !=(const Statistician& s1,
                   const Statistician& s2)
  {
	  return (!(s1 == s2));
  }

}
