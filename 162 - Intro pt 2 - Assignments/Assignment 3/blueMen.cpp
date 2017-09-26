/*****************************************************************
** Program Filename: blueMen.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: source file for BlueMen class
*****************************************************************/
//#include "stdafx.h"
#include "blueMen.hpp"


/*****************************************************************
** Function: BlueMen()
** Description: constructor
** Parameters: none
*****************************************************************/
BlueMen::BlueMen()
{
	armor = 3;
	hp = 12;
	type = "Blue Men";
}


/*****************************************************************
** Function: ~BlueMen()
** Description: destructor
** Parameters: none
*****************************************************************/
BlueMen::~BlueMen()
{
}


/*****************************************************************
** Function: attack()
** Description: calculates damage dealt
** Parameters: none
*****************************************************************/
int BlueMen::attack() //2d10
{
	int dmg = 0;
	for (int i = 0; i < 2; i++)
	{
		dmg += rand() % 10 + 1; //will return 2-20
	}
	std::cout << "Blue Men attacked for " << dmg << " points of damage!" << std::endl;
	return dmg;
}


/*****************************************************************
** Function: defend()
** Description: calculates damage taken
** Parameters: int
*****************************************************************/
int BlueMen::defend(int atk) //3d6. every 4hp lost, 1d6 is removed from defense. ie - 9-12hp = 3d6, 5-8hp = 2d6, 1-4hp = 1d6
{
	int def = 0;
	int dmg = 0;
	if (hp > 8) //3d6
	{
		std::cout << "The Blue Men are strong!" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			def += rand() % 6 + 1;
		}
	}
	else if (hp < 9 || hp > 4) //2d6
	{
		std::cout << "The Blue Men are bloodied!" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			def += rand() % 6 + 1;
		}

	}
	else //(hp < 5) 1d6
	{
		def = rand() % 6 + 1;
		std::cout << "The Blue Men are weak!" << std::endl;
	}
	def += armor; //adding armor to defense
	std::cout << "Blue Men blocked " << def << " points of damage!" << std::endl;
	dmg = atk - def; //calculating net damage
	if (dmg < 1) //no negative damage
	{
		dmg = 0;
	}

	hp -= dmg; //subtracting dmg from hp

	std::cout << "Blue Men took " << dmg << " points of damage!" << std::endl;
	std::cout << "Blue Men's remaining health: " << hp << std::endl;

	return dmg;
}


/*****************************************************************
** Function: getType()
** Description: returns type of creature
** Parameters: none
*****************************************************************/
std::string BlueMen::getType()
{
	return type;
}


/*****************************************************************
** Function: deathCheck()
** Description: determines if creature died
** Parameters: none
*****************************************************************/
bool BlueMen::deathCheck()
{
	if (hp < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
