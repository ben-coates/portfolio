// Names: Benjamin Coates and Perry Snapp
// Course: CIS-117
// Assingment 7: Excersices 1,2,5,7,8
// Both of us were present and shared in the typing of this code
// =================================================================

package chapter7;

import java.util.*;
import java.io.*;

import chapter3.Name;


public class AddressBook
{
	String filename;
	
	public AddressBook()
	{
		filename = "addressbook.txt";
	}
	
	
	public AddressBook(String newFilename)
	{
		filename = newFilename;
	}
	
	public void catchFNFException()
	{
		try
		{
			String filename = "addressbook.txt";
			Scanner in = new Scanner(new FileReader(filename));
			in.nextLine();
		}
		catch (FileNotFoundException e)
		{
			System.out.println("File does not exist");
			System.exit(0);
		}
	}
	
	public void printEntryWithName(Name name) throws IOException
	{
		catchFNFException();
		Entry entry;
		Scanner in = new Scanner(new FileReader(filename));
		try
		{
			in.nextLine(); // Go to next line
			boolean done = false;
			do // Scan file for a match
			{
				entry = new Entry(in);
				if (entry.getName().compareTo(name) == 0)
				{
					System.out.println(entry); // Output matching entry
					done = true;
				}
			} while (!done);
		}
		catch (NoSuchElementException ex)
		{
			System.out.println("No match found.");
		}
		in.close();
	}
	
	public void printEntriesWithZip(int zipCode) throws IOException
	{
		catchFNFException();
		Entry entry;
		Scanner in = new Scanner(new FileReader(filename));
		try
		{
			int numEntries = in.nextInt(); // Get number of entries on file
			in.nextLine(); // Go to next line
			for (int entryNum = 1; entryNum <= numEntries; entryNum++)
			{ // Scan file for all matches
				entry = new Entry(in);
				if (entry.getAddress().getZipCode() == zipCode)
					System.out.println(entry); // Output matching entry
			}
			if (in.hasNextLine() == true)
			{
				System.out.println("File is not empty");
			}
		}
		catch (NoSuchElementException ex)
		{
			System.out.println("File has fewer entries than indicated.");
		}
		in.close();
	}
	
	public void printEntriesWithArea(int areaCode) throws IOException
	{
		catchFNFException();
		Entry entry;
		Scanner in = new Scanner(new FileReader(filename));
		if (in.hasNextLine())
			in.nextLine(); // Go to next line
		else
			System.out.println("File is empty.");
		while (in.hasNext())
		{ // Scan file for all matches
			entry = new Entry(in);
			if (entry.getPhone().getArea() == areaCode)
				System.out.println(entry); // Output matching entry
		}
		in.close();
	}
	
	public void printEntriesWithMatchingNames(Name name2) throws IOException
	{
		catchFNFException();
		Entry entry;
		Scanner in = new Scanner(new FileReader(filename));
		if (in.hasNextLine())
			in.nextLine(); // Go to next line
		else
			System.out.println("File is empty.");
		while (in.hasNext())
		{ // Scan file for all matches
			entry = new Entry(in);
			Name entryname = entry.getName();
			String last = name2.getLastName();
			if (entryname.getLastName().compareTo(last) == 0)
			{
				System.out.println(entry); // Output matching entry
			}
		}
		in.close();
	}
	
	public void convertToObjectAddressBook() throws IOException
	{
		Entry entry;
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("addressbook.dat"));
		Scanner in = new Scanner(new FileReader(filename));
		if (in.hasNextLine())
			in.nextLine();
		else
			System.out.println("File is empty.");
		while (in.hasNext())
		{
			entry = new Entry(in);
			out.writeObject(entry);
		}
		out.close();
		in.close();
	}
	
	public static void main(String[] args) throws IOException
	{
		AddressBook ab = new AddressBook();
		ab.convertToObjectAddressBook();
	}
}