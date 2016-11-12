// Names: Benjamin Coates and Perry Snapp
// Course: CIS-117
// Assingment 7: Excersices 1,2,5,7,8
// Both of us were present and shared in the typing of this code
// =================================================================

package chapter7;
public class Phone
{
	int area;
	int exchange;
	int number;
	
	public Phone()
	{
		area = 999;
		exchange = 999;
		number = 9999;
	}
	
	public Phone(int newArea, int newExch, int newNum) throws Exception
	{
		if ( newArea < 200 || newArea > 999 || newArea == 911 ||
			newExch < 200 || newExch > 999 || newExch == 911 ||
			newNum < 0 || newNum > 9999)
			throw new Exception("Invalid phone number: (" + newArea + ")" +
								newExch + "-" + newNum);
		else
		{
			area = newArea;
			exchange = newExch;
			number = newNum;
		}
	}
	
	public int getArea()
	{
		return area;
	}
	public int getExchange()
	{
		return exchange;
	}
	public int getNumber()
	{
		return number;
	}
	public String toString()
	{
		return "(" + area + ")" + exchange + "-" + number;
	}
}
