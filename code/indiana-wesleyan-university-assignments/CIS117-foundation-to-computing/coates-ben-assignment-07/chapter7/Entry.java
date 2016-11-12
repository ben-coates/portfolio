// Names: Benjamin Coates and Perry Snapp
// Course: CIS-117
// Assingment 7: Excersices 1,2,5,7,8
// Both of us were present and shared in the typing of this code
// =================================================================

package chapter7;

import java.util.*;

import chapter3.Name;
import chapter6.Address;

public class Entry
{
	Name name;
	
	Address address;
	
	Phone phone;
	
	// Default constructor
	public Entry()
	{
		name = new Name();
		address = new Address();
		phone = new Phone();
	}
	
	// Direct constructor
	public Entry(Name newName, Address newAddr, Phone newPhone)
	{
		name = newName;
		address = newAddr;
		phone = newPhone;
	}
	
	// Scanner-based constructor
	public Entry(Scanner in)
	{
		String first = in.next();
		String last = in.next();
		String middle = in.next();
		String separator = in.nextLine();
		name = new Name(first, last, middle);
		address = new Address(in);
		int area = in.nextInt();
		int exch = in.nextInt();
		int numb = in.nextInt();
		try
		{
			phone = new Phone(area, exch, numb);
		} catch (Exception ex)
		{
			phone = new Phone();
		}
	}
	
	// Observers
	public Name getName()
	{
		return name;
	}
	
	public Address getAddress()
	{
		return address;
	}
	
	public Phone getPhone()
	{
		return phone;
	}
	
	public String toString()
	{
		return name.toString() + '\n' + address.toString() + '\n'
		+ phone.toString();
	}
}
