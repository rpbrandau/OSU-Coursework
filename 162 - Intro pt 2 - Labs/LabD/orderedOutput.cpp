/*****************************************************************
** Program Filename: orderedOutput.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Source file for OrderedOutput class
*****************************************************************/
//#include "stdafx.h"
#include "orderedOutput.hpp"


/*****************************************************************
** Function: OrderedOutput()
** Description: Constructor
** Parameters: none
*****************************************************************/
OrderedOutput::OrderedOutput()
{
	position = 0;
}


/*****************************************************************
** Function: ~OrderedOutput()
** Description: Destructor
** Parameters: none
*****************************************************************/
OrderedOutput::~OrderedOutput()
{

}


/*****************************************************************
** Function: transform()
** Description: adds a space every 5 characters
** Parameters: char variable
*****************************************************************/
char OrderedOutput::transform(char ch)
{
	char x = ' ';
	if (((ch > 64) && (ch < 91)) || ((ch > 96) && (ch < 123))) //if it's a character
	{
		if (position % 5 != 0)
		{
			position++;
			return ch;
		}
		else
		{
			position++;
			return x;
		}
	}
	else
	{
		position++;
		return ch;
	}
	
}
