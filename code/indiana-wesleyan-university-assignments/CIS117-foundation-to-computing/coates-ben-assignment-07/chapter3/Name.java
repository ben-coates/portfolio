package chapter3;
//****************************************************************
//  Class Name
//  Implements a basic class representing a name with three parts.
//****************************************************************
public class Name
{
  String first;                      // Person's first name
  String last;                       // Person's last name
  String middle;                     // Person's middle name
  
  // Constructors
  public Name()                      // Assign empty strings to fields
  {
    first = "";
    last = "";
    middle = "";
  }
  
  public Name(String firstName, String lastName, String middleName)
  {
    first = firstName;               // Assign parameters to fields
    last = lastName;
    middle = middleName;
  }
  
  // Observer methods
  public String getFirstName()
  {
    return first;
  }
  
  public String getMiddleName()
  {
    return middle;
  }
  
  public String getLastName()
  {
    return last;
  }
  
  public String toString() {
	  return last + ", " + first + " " + middle;
  }
  
  // Operations
  public int compareTo(Name other)
  {
    int compare = last.toLowerCase().compareTo(other.getLastName().toLowerCase());
    if ( compare != 0)
      return compare;
    else 
    {
      compare = first.toLowerCase().compareTo(other.getFirstName().toLowerCase());
      if (compare != 0)
        return compare;
      else
        return middle.toLowerCase().compareTo(other.getMiddleName().toLowerCase());
    }
  }

}
