/*****************************************************************
** Program Filename: critter.hpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: sourcefile for critter class
*****************************************************************/
//#include "stdafx.h"
#include "critter.hpp"
#include <stdlib.h>


/*****************************************************************
** Function: Critter()
** Description: default constructor
** Parameters: none
*****************************************************************/
Critter::Critter()
{
	breedCounter = 0;
	eatCounter = 0;
}


/*****************************************************************
** Function: move()
** Description: returns a value that is used for critter movement
** Parameters: none
*****************************************************************/
int Critter::move()
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
bool Critter::breed()
{
	//if breedCounter == 3 or 8, return true. reset breedCounter.
	//else return false & increment breedCounter.
	breedCounter++;
	return false;

}


/*****************************************************************
** Function: eat()
** Description: incriments eatCounter
** Parameters: none
*****************************************************************/
bool Critter::eat()
{
	//if able to eat, return true. reset eatCounter.
	//else, return false & increment eatCounter
	eatCounter++;
	return true;
}


/*****************************************************************
** Function: death()
** Description: determines if critter dies
** Parameters: none
*****************************************************************/
bool Critter::death()
{
	//if death counter 3 or 10, return true.
	//else return false, deathCounter++.
	return false;
}


/*****************************************************************
** Function:critterType()
** Description: returns type of critter
** Parameters: none
*****************************************************************/
char Critter::critterType()
{
	char c = 'C';
	return c;
}
