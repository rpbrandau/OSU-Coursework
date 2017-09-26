/****************************************
* Program Filename: sumMainEx.cpp
* Author: Riley Brandau
* Date: 6/21/16
* Description: main method for extra credit sum function
* **************************************/

#include "summation.hpp"
#include <iostream>


int main()
{
	double summation = 0.0;
	int size = 0;
	double num = 0;
	std::cout << "Please enter an integer for the size of the array: " << std::endl;
	std::cin >> size;
	double *arrayEx = new double[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "Please enter a number for array position " << i + 1 << " of " << size << ":" << std::endl;
		std::cin >> num;
		arrayEx[i] = num;
	}
	summation = sum(arrayEx, size);
	std::cout << "The sum of arrayEx is: " << summation << "." << std::endl;
	delete[] arrayEx;
	return 0;
}

