/****************************************
* Program Filename: average.cpp
* Author: Riley Brandau
* Date: 6/21/16
* Description: source file for average function
* **************************************/
//#include "stdafx.h"
#include "average.hpp"


/***********************************************************************
* Function: avg()
* Description: Returns the average of an array of doubles
* ********************************************************************/
double avg(double *array, int arraySize)
{
	double avg = 0;

	for (int i = 0; i < arraySize; i++)
	{
		avg += array[i];
	}
	
	avg = (avg / arraySize);
	
	return avg;
}
