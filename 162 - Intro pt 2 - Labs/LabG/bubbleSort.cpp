/*****************************************************************
** Program Filename: bubbleSort.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/7/16
** Description: performs a bubblesort on an array
** Source: pg 607 of textbook
*****************************************************************/
//#include "stdafx.h"
#include "bubbleSort.hpp"


void bubbleSort(int list[], int arraySize)
{
	int temp = 0;
	bool swap = false;

	do
	{
		swap = false;
		for (int i = 0; i < (arraySize - 1); i++)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap == true);
}
