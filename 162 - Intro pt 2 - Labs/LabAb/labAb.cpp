/*****************************************************************
** Program Filename: labAb.cpp
** Author: Riley Brandau
** Date: 7/12/16
** Description: Using another student's code for use in a program
*****************************************************************/

//#include "stdafx.h"
#include "average.hpp"
#include "summation.hpp"
#include <iostream>

int main()
{	/* Test Arrays
	double avgArray[5] = { 10.1,12.3,2.6,3.4,20.7 };
	double sumArray[5] = { 5.5,6.7,8.9,16.3,21.1 };
	*/
	double userAvgArray[5];
	double userSumArray[5];

	double result = 0;
	
	/* Test Output
	std::cout << "Average of array = ";
	result = avg(avgArray, 5);
	std::cout << result << std::endl;
	std::cout << "Should be 9.82" << std::endl;
	std::cout << std::endl;

	std::cout << "Sum of array = ";
	result = sum(sumArray, 5);
	std::cout << result << std::endl;
	std::cout << "Should be 58.5" << std::endl;
	*/

	std::cout << "Please enter 5 numbers to be averaged:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Number " << i + 1 << ":" << std::endl;
		while (!(std::cin >> userAvgArray[i])) //validation
		{
			std::cout << "Please enter an int or double." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	result = avg(userAvgArray, 5);
	std::cout << "Average of array: " << result << std::endl;

	std::cout << "Please enter 5 numbers to be summed:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Number " << i + 1 << ":" << std::endl;
		while (!(std::cin >> userSumArray[i])) //validation
		{
			std::cout << "Please enter an int or double." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	result = sum(userSumArray, 5);
	std::cout << "Sum of array: " << result << std::endl;


    return 0;
}

