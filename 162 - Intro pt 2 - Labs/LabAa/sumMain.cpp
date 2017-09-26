/****************************************
* Program Filename: sumMain.cpp
* Author: Riley Brandau
* Date: 6/21/16
* Description: main method for testing sum function
* **************************************/

#include "summation.hpp"
#include <iostream>


int main()
{
	double summation = 0.0;
	double arrayA[5] = { 0.5,5.5,10.5,15.5,20.5 };
	double arrayB[10] = { 0.3, 7.2, 16.4, 133.1, 192, 1000.25, 13.5, 27.6, 22.3, 1986.9 };

	summation = sum(arrayA, 5);
	std::cout << "The sum of arrayA is: " << summation << "." << std::endl;
	std::cout << std::endl;

	summation = sum(arrayB, 10);
	std::cout << "The sum of arrayB is: " << summation << "." << std::endl;
	std::cout << std::endl;

	return 0;
}
