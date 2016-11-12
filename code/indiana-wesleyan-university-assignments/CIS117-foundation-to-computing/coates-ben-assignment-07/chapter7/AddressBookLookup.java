// Names: Benjamin Coates and Perry Snapp
// Course: CIS-117
// Assingment 7: Excersices 1,2,5,7,8
// Both of us were present and shared in the typing of this code
// =================================================================

package chapter7;

//*************************************************************************
// Application AddressBookLookup searches for entries in an address book on
// file addressbook.txt. It supports three kinds of queries:
//   1: first entry with matching name
//   2: all entries with matching zip code
//   3: all entries with matching area code
// It catches errors in which an invalid entry is specified, or when the
// number of entries specified is greater than the number on the file
//*************************************************************************
import java.util.*;
import java.io.*;

import chapter3.Name;

public class AddressBookLookup
{
	public static void main(String[] args) throws IOException
	{
		AddressBook book = new AddressBook();
		System.out.println("Enter the number of the type of search "
						   + "you would like to perform:");
		System.out.println("1: First entry with matching name");
		System.out.println("2: All entries with matching zip code");
		System.out.println("3: All entries with matching area codes");
		System.out.println("4: All entries with matching last names");
		Scanner in = new Scanner(System.in);
		int type = in.nextInt(); // Get search type
		switch (type)
		{
			case 1: // First entry with matching name
				System.out.print("Enter name (first last middle): ");
				String first = in.next(); // Get name to match
				String last = in.next();
				String middle = in.next();
				Name name = new Name(first, last, middle);
				System.out.println(); // Output a blank line
				book.printEntryWithName(name); // Output the matching entry
				break;
			case 2: // All entries with matching zip code
				System.out.print("Enter zip code: ");
				int zipCode = in.nextInt(); // Get zip code to match
				System.out.println(); // Output a blank line
				book.printEntriesWithZip(zipCode); // Output the matching entries
				break;
			case 3: // All entries with matching area code
				System.out.print("Enter area code: ");
				int areaCode = in.nextInt(); // Get area code to match
				System.out.println(); // Output a blank line
				book.printEntriesWithArea(areaCode); // Output the matching entries
				break;
			case 4: // All entries with matching Last names
				System.out.print("Enter last name: ");
				String firstname = ""; // Get name to match
				String lastname = in.next();
				String middlename = "";
				Name name2 = new Name(firstname, lastname, middlename);
				System.out.println(); // Output a blank line
				book.printEntriesWithMatchingNames(name2); // Output the matching entries
				break;
			default:
				System.out.println("Invalid search selected.");
		}
	}
}
