/*****************************************************************
** Program Filename: loadedDice.cpp
** Author: Riley Brandau
** Date: 6/29/16
** Description: source file for loadedDice derived class
*****************************************************************/
//#include "stdafx.h"
#include "dice.hpp"
#include "loadedDice.hpp"
#include <stdlib.h> //needed for rand
#include <time.h> //needed for time
#include <iostream>


/*****************************************************************
** Function: LoadedDice()
** Description: default constructor
** Parameters: none
*****************************************************************/
LoadedDice::LoadedDice()
{
	sides = 6;
}


/*****************************************************************
** Function: LoadedDice()
** Description: constructor
** Parameters: int
*****************************************************************/
LoadedDice::LoadedDice(int s)
{
	sides = s;
}


/*****************************************************************
** Function: roll()
** Description: overloaded roll() function. 5% chance to add 1 to a non-max roll
** Parameters: none
*****************************************************************/
int LoadedDice::roll()
{
	int roll = 0;
	roll = rand() % sides + 1;
	//std::cout << "Roll before possible mod 1...: " << roll << std::endl;

	if (roll < sides)
	{
		int chance = 0;
		chance = rand() % 100 + 1;
		//std::cout << "Chance for +1 mod (96-100) = " << chance << std::endl;
		if (chance > 95)
		{
			//std::cout << "Roll before +1: " << roll << std::endl;
			roll = roll + 1;
			std::cout << "Roll given +1: " << roll << std::endl;
		}
	}
	return roll;
}
