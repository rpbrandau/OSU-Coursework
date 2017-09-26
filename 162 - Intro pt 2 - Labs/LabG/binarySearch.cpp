/*****************************************************************
** Program Filename: binarySearch.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/7/16
** Description: performs a binary search on an array
** Source: pg 598-599 of textbook
*****************************************************************/
//#include "stdafx.h"
#include "binarySearch.hpp"

int binarySearch(int list[], int size, int searchFor)
{
	int first = 0;
	int middle = 0;
	int last = size - 1;
	bool found = false;
	int pos = -1;

	while (found == false && first <= last)
	{
		middle = (first + last) / 2;
		if (list[middle] == searchFor)
		{
			found = true;
			pos = middle;
		}
		else if (list[middle] > searchFor)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return pos;
}
