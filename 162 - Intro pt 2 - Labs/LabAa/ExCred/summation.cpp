/****************************************
* Program Filename: summation.cpp
* Author: Riley Brandau
* Date: 6/21/16
* Description: source file for summation function
* **************************************/
//#include "stdafx.h"
#include "summation.hpp"


/***********************************************************************
* Function: sum()
* Description: Returns the sum of an array of doubles
* ********************************************************************/
double sum(double *array, int arraySize)
{
	double sum = 0;

	for (int i = 0; i < arraySize; i++)
	{
		sum += array[i];
	}

	return sum;
}
