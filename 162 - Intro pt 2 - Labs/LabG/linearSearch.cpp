/*****************************************************************
** Program Filename: linearSearch.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/7/16
** Description: function to do a linear search on an array
** Source: pg. 596 in textbook
*****************************************************************/
//#include "stdafx.h"
#include "linearSearch.hpp"

int linearSearch(const int list[], int searchFor, int arrSize)
{
	bool found = false;
	int pos = -1;
	int index = 0;

	while (index < arrSize && found == false)
	{
		if (list[index] == searchFor)
		{
			found = true;
			pos = index;
		}
		index++;
	}
	return pos;
}
