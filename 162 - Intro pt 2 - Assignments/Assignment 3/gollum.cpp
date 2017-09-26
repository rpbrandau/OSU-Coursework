/*****************************************************************
** Program Filename: gollum.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: source file for Gollum class
*****************************************************************/
//#include "stdafx.h"
#include "gollum.hpp"


/*****************************************************************
** Function: Gollum()
** Description: constructor
** Parameters: none
*****************************************************************/
Gollum::Gollum()
{
	armor = 3;
	hp = 8;
	type = "Gollum";
}


/*****************************************************************
** Function: ~Gollum()
** Description: destructor
** Parameters: none
*****************************************************************/
Gollum::~Gollum()
{

}


/*****************************************************************
** Function: attack()
** Description: calculates damage dealt
** Parameters: none
*****************************************************************/
int Gollum::attack() //1d6. 5% chance to deal 3d6
{
	int dmg = 0;
	int bonus = 0;
	bonus = rand() % 100 + 1; //1-100 roll
	if (bonus < 6) //5% chance
	{
		std::cout << "Gollum used THE ONE RING! Where'd he go??" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			dmg += rand() % 6 + 1;
		}
	}
	else
	{
		dmg = rand() % 6 + 1;
	}
	std::cout << "Gollum attacked for " << dmg << " points of damage!" << std::endl;
	return dmg;

}


/*****************************************************************
** Function: defend()
** Description: calculates damage taken
** Parameters: int
*****************************************************************/
int Gollum::defend(int atk) //1d6
{
	int def = 0;
	int dmg = 0;

	def = rand() % 6 + 1; //defense roll
	def += armor; //add armor to defense roll
	std::cout << "Gollum blocked " << def << " points of damage!" << std::endl;
	dmg = atk - def; //calculating net damage
	if (dmg < 1) //no negative damage
	{
		dmg = 0;
	}

	hp -= dmg; //subtracting dmg from hp

	std::cout << "Gollum took " << dmg << " points of damage!" << std::endl;
	std::cout << "Gollum's remaining health: " << hp << std::endl;

	return dmg;
}


/*****************************************************************
** Function: getType()
** Description: returns type of creature
** Parameters: none
*****************************************************************/
std::string Gollum::getType()
{
	return type;
}


/*****************************************************************
** Function: deathCheck()
** Description: determines if creature died
** Parameters: none
*****************************************************************/
bool Gollum::deathCheck()
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
