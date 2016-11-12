// Benjamin Coates
// CIS 336: Programming Languages
// FA 2014
// Dr. Joe Hoffert
// Assignment 3, Problem 2
// =========================================

using System;

class problem2
{

	private static int fun (ref int k) {
    	k += 4;
    	return 3 * (k) - 1;
}

	public static void Main () {
    	int i = 10, j = 10, sum1, sum2;
    	sum1 = (i/2) + fun(ref i);
    	sum2 = fun(ref j) + (j / 2);

    	Console.WriteLine(sum1);
    	Console.WriteLine(sum2);
	}
}