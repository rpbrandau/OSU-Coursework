/**********
 * Author: Riley Brandau
 * Date: 1/21/16
 * Description: Assignment 4.b - This program/function will take three int parameters by reference, and sorts their
 * values into ascending order, where the first parameter now has the lowest value, the second parameter has the middle value,
 * and the third has the highest value.
**********/

#include <iostream>

using namespace std;

void smallSort(int &rNum1, int &rNum2, int &rNum3); //smallSort prototype

/****************************
 * main function to test smallSort function

int main()
{
	int num1,
	    num2,
	    num3;

	cout << "Please enter three integers and I will arrange them small to large." << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;

	smallSort(num1, num2, num3);

	cout << "your numbers in ascending order:" << endl;
	cout << num1 << ", " << num2 << ", " << num3 << endl;

	return 0;
}
******************************/

void smallSort(int &rNum1, int &rNum2, int &rNum3)
{
	int swap;

	if (rNum1 > rNum2)
	{
		swap = rNum1;
		rNum1 = rNum2;
		rNum2 = swap;
	}

	if (rNum2 > rNum3)
	{
		swap = rNum2;
		rNum2 = rNum3;
		rNum3 = swap;
	}
}
