/*****************************************************************
** Program Filename: doodlebug.cpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: sourcefile for doodlebug class
*****************************************************************/
//#include "stdafx.h"
#include "doodlebug.hpp"
#include <stdlib.h>

/*****************************************************************
** Function: Doodlebug()
** Description: default constructor
** Parameters: none
*****************************************************************/
Doodlebug::Doodlebug()
{
	breedCounter = 0;
	eatCounter = 0;
}


/*****************************************************************
** Function: Doodlebug()
** Description: constructor
** Parameters: 2 ints
*****************************************************************/
Doodlebug::Doodlebug(int x, int y)
{
	breedCounter = 0;
	eatCounter = 0;
	this->x = x;
	this->y = y;
}


/*****************************************************************
** Function: move()
** Description: returns a value that is used for critter movement
** Parameters: none
*****************************************************************/
int Doodlebug::move()
{
	int m;
	m = rand() % 4; //returns 0-3
	return m;
}


/*****************************************************************
** Function: breed()
** Description: determines if critter should spawn.
** Parameters: none
*****************************************************************/
bool Doodlebug::breed()
{
	if (breedCounter == 8)
	{
		breedCounter = 0;
		return true;
	}
	else
	{
		breedCounter++;
		return false;
	}
}


/*****************************************************************
** Function: eat()
** Description: incriments eatCounter
** Parameters: none
*****************************************************************/
bool Doodlebug::eat()
{
	eatCounter++;
	return true; //need to change
}


/*****************************************************************
** Function: death()
** Description: determines if critter dies
** Parameters: none
*****************************************************************/
bool Doodlebug::death()
{
	if (eatCounter == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*****************************************************************
** Function:critterType()
** Description: returns type of critter
** Parameters: none
*****************************************************************/
char Doodlebug::critterType()
{
	char c = 'D';
	return c;
}
