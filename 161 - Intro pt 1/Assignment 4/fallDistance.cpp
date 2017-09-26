/**********
 * Author: Riley Brandau
 * Date: 1/21/16
 * Description: Assignment 4.a - Write a function named fallDistance that takes the falling time as an argument
 * and then returns the distance in meters that the object has fallin in that amount of time. 
 * use the formula d = (1/2)gt^2
***********/

#include <iostream>
#include <iomanip> //needed for using setprecision/string manipulators, if wanted.

using namespace std;

double fallDistance(double number); //fallDistance prototype


/**********
 * main function for testing fallDistance
 *
int main()
{
	double meters;
	double number;
	
	cout << fixed << showpoint << setprecision(2);

	cout << "Please enter the amount of time, in seconds, an object has fallen:" << endl;
	cin >> number;

	meters = fallDistance(number); // calling the fallDistance function

	cout << "the object has fallen " << meters  << " meters in that amount of time." << endl;

	return 0;
}
**********/

/*****
 * This function computes fall distance and sends the value back to the function that called it
*****/

double fallDistance(double number)
{
	const double gravity = 9.8; //defining the constant gravity
	double distance;

	distance = ((1.0/2.0)*gravity)*(number*number); //calculates the distance fallen

	return distance; //passes the distance fallen back to the function that called it
}

