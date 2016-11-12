// Names: Benjamin Coates and Perry Snapp
// Course: CIS-117
// Assingment 7: Excersices 1,2,5,7,8
// Both of us were present and shared in the typing of this code
// =================================================================

package chapter6;
//*********************************************************************
// This class represents an address
//*********************************************************************
import java.util.Scanner;
import java.io.*;
public class Address
{
	String street;        // Street address
	String city;          // City part of the address
	String state;         // The state (two-letter abbreviation)
	int zipCode;
	
	public Address()      // Default constructor
	{
		street = "";
		city = "";
		state = "";
		zipCode = 0;
	}
	
	public Address(Scanner in)           // Scanner constructor
	{
		street = in.nextLine();
		city = in.next();
		state = in.next();
		zipCode = in.nextInt();
		String separator = in.nextLine();  // Read past end-of-line mark
	}
	
	// Field get methods
	public String getStreet() {return street;}
	public String getCity() {return city;}
	public String getState() {return state;}
	public int getZipCode() {return zipCode;}
	
	public String toString()
	{
		return street + '\n' + city + ", " + state + "  " + zipCode;
	}
}