/*****************************************************************
** Program Filename: dice.cpp
** Author: Riley Brandau
** Date: 6/29/16
** Description: source file for dice class
*****************************************************************/
//#include "stdafx.h"
#include "dice.hpp"
#include <stdlib.h> //needed for rand
#include <time.h> //needed for time


/*****************************************************************
** Function: Dice()
** Description: default constructor
** Parameters: none
*****************************************************************/
Dice::Dice()
{
	sides = 6;
}


/*****************************************************************
** Function: Dice()
** Description: constructor
** Parameters: int
*****************************************************************/
Dice::Dice(int s)
{
	sides = s;
}


/*****************************************************************
** Function: roll()
** Description: returns a value between 1 and the sides a die has
** Parameters: none
*****************************************************************/
int Dice::roll()
{
	int roll = 0;
	roll = rand() % sides + 1;
	return roll;
}
