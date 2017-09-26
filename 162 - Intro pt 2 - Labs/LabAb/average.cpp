/*********************************************************************
** Program Filename: average.cpp
** Description: Defines function to calculate average.
** Input: Array and size of array.
** Output: Average.
*********************************************************************/
//#include "stdafx.h"
#include "average.hpp"

/*********************************************************************
** Function: avg
** Description: Calculates average of an array.
** Parameters: Constant double array, integer for size of array.
** Pre-Conditions: Array must be created to call this function.
** Post-Conditions: Calculated average is returned as a double type.
*********************************************************************/

double avg(const double array[], int size)
{
	double sum = 0.;                     /* holds sum calcualation*/
	double average;                 /* holds average calculation*/

	for (int i = 0; i < size; i++)
		sum += array[i];

	average = sum / size;

	return average;
}
