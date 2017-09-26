/****************************************
* Program Filename: avgMain.cpp
* Author: Riley Brandau
* Date: 6/21/16
* Description: main method for testing avg function
* **************************************/

#include "average.hpp"
#include <iostream>


int main()
{
	double average = 0.0;
	double arrayA[5] = { 0.5,5.5,10.5,15.5,20.5 };
	double arrayB[10] = { 0.3, 7.2, 16.4, 133.1, 192, 1000.25, 13.5, 27.6, 22.3, 1986.9 };

	average = avg(arrayA, 5);
	std::cout << "The average of arrayA is: " << average << "." << std::endl;
	std::cout << std::endl;

	average = avg(arrayB, 10);
	std::cout << "The average of arrayB is: " << average << "." << std::endl;
	std::cout << std::endl;
}
