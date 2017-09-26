/**********
 * Author: Riley Brandau
 * Date: 1/21/16
 * Description: Assingment 4.c - This void function takes a positive integer input by the user and will then perform
 * a "hailstone sequence" on it. It will then calculate how many steps it took to get to 1, and will return that
 * value to the function that called it.
 *
 * Hailstone calculations-
 * If integer is even: x = x/2
 * If integer is odd: x = (x*3)+1
 *
**********/

#include <iostream>

using namespace std;

int hailstone(int num); //hailstone prototype

/**********
 * Main function for testing hailstone function.

int main()
{
	int num,
	    steps;

	cout << "Please enter an integer for me to perform a ""hailstone sequence"" on." << endl;
	cin >> num;

	steps = hailstone(num);

	cout << "It took " << steps << " steps to arrive at 1." << endl;

	return 0;
}
**********/

//this function performes a hailstone sequence on the entered integer then returns how many steps it took
int hailstone(int num)
{
	int count; //this will keep track of how many steps the sequence took

	while (num !=1)
	{
		if (num % 2 == 0) //tests to see if integer is even
		{
			num = num/2;
			count++;
		}
		else
		{
			num = (num*3)+1;
			count++;
		}
	}

	return count; //returns the steps it took to the function that called it
}
