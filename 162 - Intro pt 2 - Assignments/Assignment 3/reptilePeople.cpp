/*****************************************************************
** Program Filename: reptilePeople.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: source file for ReptilePerson class
*****************************************************************/
//#include "stdafx.h"
#include "reptilePeople.hpp"


/*****************************************************************
** Function: ReptilePeople()
** Description: constructor
** Parameters: none
*****************************************************************/
ReptilePeople::ReptilePeople()
{
	armor = 7;
	hp = 18;
	type = "Reptile Person";
}


/*****************************************************************
** Function: ~ReptilePeople()
** Description: destructor
** Parameters: none
*****************************************************************/
ReptilePeople::~ReptilePeople()
{
}


/*****************************************************************
** Function: attack()
** Description: calculates damage dealt
** Parameters: none
*****************************************************************/
int ReptilePeople::attack() //3d6
{
	int dmg = 0;
	for (int i = 0; i < 3; i++)
	{
		dmg += rand() % 6 + 1; //will return 3-18
	}
	std::cout << "Reptile Person attacked for " << dmg << " points of damage!" << std::endl;
	return dmg;
}


/*****************************************************************
** Function: defend()
** Description: calculates damage taken
** Parameters: int
*****************************************************************/
int ReptilePeople::defend(int atk) //1d6
{
	int def = 0;
	int dmg = 0;

	def = rand() % 6 + 1; //defense roll
	def += armor; //add armor to defense roll
	std::cout << "Reptile Person blocked " << def << " points of damage!" << std::endl;
	dmg = atk - def; //calculating net damage
	if (dmg < 1) //no negative damage
	{
		dmg = 0;
	}

	hp -= dmg; //subtracting dmg from hp

	std::cout << "Reptile Person took " << dmg << " points of damage!" << std::endl;
	std::cout << "Reptile Person's remaining health: " << hp << std::endl;

	return dmg;
}


/*****************************************************************
** Function: getType()
** Description: returns type of creature
** Parameters: none
*****************************************************************/
std::string ReptilePeople::getType()
{
	return type;
}


/*****************************************************************
** Function: deathCheck()
** Description: determines if creature died
** Parameters: none
*****************************************************************/
bool ReptilePeople::deathCheck()
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
