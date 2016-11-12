// Names: Benjamin Coates and Ashan Rodrigo
// Course: CIS-117
// Exercise: 5 pg. 274
// Lab: Chapter 5 Lab
// Descritption: Calculates the diameter, circumference or area of a circle from the user inputed radius
// Ben and Ashan were both present and typed this document

//imports scanner classs
import java.util.Scanner;

public class CircleCalc
{
	public static void main (String args[])
	{
		// Declares variables.
		float radius;
		final double PI = 3.14159265; // Immutable variable
		char action;
		double result;
		String output;
		
		// Initializes the scanner.
		Scanner in = new Scanner(System.in);
		
		// Asks for user input.
		System.out.print("Enter the radius of the circle as a decimal (float) value: ");
		radius = in.nextFloat();
		// Asks user for desired calculation and provides option to quit program.
		System.out.print("Choose one of the following to get the relavent output"
						 +"\n-\"A\" for Area"
						 +"\n-\"C\" for Circumference"
						 +"\n-\"D\" for Diameter"
						 +"\n-\"Q\" to quit program"
						 +"\nhere: ");
		// do provides a loop to keep the program running until user ends it.
		do{
			// Action recieves input from user. Only takes first character inputed.
			// Thus input such as "abca" will output Area case.
			action = in.next().charAt(0);
			// Using a switch case to output the correct value/string for the input.
			switch (action) {
					// Case 'A' and 'a' makes input non-case sensitive. Calculates and gives output for Area.
				case 'A':
				case 'a':{
					output = "The area of the circle with radius " + radius + " is " + (PI * (radius * radius)) + ".";
					break;
				}
					// Case 'C' and 'c' makes input non-case sensitive. Calculates and gives output for Circumference.
				case 'C':
				case 'c':{
					output = "The circumference of the circle with radius " + radius + " is " + (2 * PI * radius) + ".";
					break;
				}
					// Case 'D' and 'd' makes input non-case sensitive. Calculates and gives output for Diameter.
				case 'D':
				case 'd':{
					output = "The diameter of the circle with radius " + radius + " is " + (2 * radius) + ".";
					break;
				}
					// Case 'Q' and 'q' makes input non-case sensitive. Provides output to let user know what happens.
				case 'Q':
				case 'q':{
					output = "Exiting Program";
					break;
				}
					// Provides message upon recieving invalid input (i.e. non acceptable character).
				default:{
					output = "Invalid input";
					break;
				}
			}
			//Outputs the correct string.
			System.out.println(output);
			//Asks for next case wanted.
			System.out.print("next: ");
		} while(!(action == 'Q' || action == 'q'));
	}
}