/*****************************************************************
** Program Filename: ant.cpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: sourcefile for ant class
*****************************************************************/
//#include "stdafx.h"
#include "ant.hpp"
#include <stdlib.h>


/*****************************************************************
** Function: ant()
** Description: default constructor
** Parameters: none
*****************************************************************/
Ant::Ant()
{
	breedCounter = 0;
	eatCounter = 0;
}


/*****************************************************************
** Function: ant()
** Description: constructor
** Parameters: 2 ints
*****************************************************************/
Ant::Ant(int x, int y)
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
int Ant::move()
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
bool Ant::breed()
{
	if (breedCounter == 3)
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
bool Ant::eat()
{
	eatCounter++;
	return true;
}


/*****************************************************************
** Function: death()
** Description: determines if critter dies
** Parameters: none
*****************************************************************/
bool Ant::death()
{
	if (eatCounter == 10)
	{
		die = true;
		return true;
	}
	else
	{
		die = false;
		eatCounter++;
		return false;
	}
}


/*****************************************************************
** Function:critterType()
** Description: returns type of critter
** Parameters: none
*****************************************************************/
char Ant::critterType()
{
	char c = 'A';
	return c;
}
