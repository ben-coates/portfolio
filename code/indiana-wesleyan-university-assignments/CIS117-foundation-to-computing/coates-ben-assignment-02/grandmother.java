//*******************************************************************************
// grandmother.java
// An application that prints the turns of "My Grandmother's Trunk" game
// Name: Benjamin Coates
// Assignment: Lab 2/Ch. 2: Simple Input/Output Program
// Course: CIS-117-A
//******************************************************************************* 
public class grandmother
{
	// Class declarations
	static final char BLANK = ' ';													// One blank character
	static final char COMMA = ',';													// A single comma
	static final char PERIOD = '.';													// a single period
	static final String BAB = " and ";												// a BLANK + and + BLANK
	static final String GRANDMASTRUNK = "In my Grandma's trunk I packed a";			// The basic "In my grandma's..." string
	static final String WORDONE = "pencil";											// The first person's word
	static final String WORDTWO = "paper";											// The second person's word
	static final String WORDTHREE = "eraser";										// The third person's word
	static final String WORDFOUR = "Bible";											// The forth person's word
	static final String WORDFIVE = "blanket";										// The fifth person's word
	
	public static void main(String[] args)
	{
		// local declarations
		String currentString;														// A string to keep the items in Grandma's Trunk
		currentString = GRANDMASTRUNK + BLANK + WORDONE;							// Sets the current string
		System.out.println(currentString + PERIOD);									// Prints the first turn
		System.out.println(currentString + BAB + WORDTWO + PERIOD);					// Prints the second turn
		currentString = currentString + COMMA + BLANK + WORDTWO;						// Resets the current string
		System.out.println(currentString + BAB + WORDTHREE + PERIOD);				// Prints the third turn
		currentString = currentString + COMMA + BLANK + WORDTHREE;					// Resets the current string
		System.out.println(currentString + BAB + WORDFOUR + PERIOD);					// Prints the fourth turn
		currentString = currentString + COMMA + BLANK + WORDFOUR;					// Resets the current string
		System.out.println(currentString + BAB + WORDFIVE + PERIOD);					// Prints the fifth turn
	}
}

// I typed this entire program on my own