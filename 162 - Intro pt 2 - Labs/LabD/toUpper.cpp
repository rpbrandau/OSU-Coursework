/*****************************************************************
** Program Filename: toUpper.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Source file for ToUpper class
*****************************************************************/
//#include "stdafx.h"
#include "toUpper.hpp"


/*****************************************************************
** Function: ToUpper()
** Description: constructor
** Parameters: none
*****************************************************************/
ToUpper::ToUpper()
{

}


/*****************************************************************
** Function: ~ToUpper()
** Description: destructor
** Parameters: none
*****************************************************************/
ToUpper::~ToUpper()
{

}


/*****************************************************************
** Function: transform()
** Description: Changes lowercase characters to uppercase
** Parameters: char variable
*****************************************************************/
char ToUpper::transform(char ch)
{
	char x = ch;
	if ((x > 96) && (x < 123)) //if it's a lowercase letter, process it
	{
		x = x-32;
		return x;
	}
	else  //if it's already uppercase or punctuation, do nothing
	{
		x = ch;
		return x;
	}
}
