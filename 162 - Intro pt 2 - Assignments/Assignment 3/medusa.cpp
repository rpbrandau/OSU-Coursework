/*****************************************************************
** Program Filename: medusa.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: source file for Medusa class
*****************************************************************/
//#include "stdafx.h"
#include "medusa.hpp"


/*****************************************************************
** Function: Medusa()
** Description: constructor
** Parameters: none
*****************************************************************/
Medusa::Medusa()
{
	armor = 3;
	hp = 8;
	type = "Medusa";
}


/*****************************************************************
** Function: ~Medusa()
** Description: destructor
** Parameters: none
*****************************************************************/
Medusa::~Medusa()
{

}


/*****************************************************************
** Function: attack()
** Description: calculates damage dealt
** Parameters: none
*****************************************************************/
int Medusa::attack() //2d6 - on a crit(12) insta-kill oponent
{
	int dmg = 0;
	for (int i = 0; i < 2; i++)
	{
		dmg += rand() % 6 + 1; //will return 2-12
	}
	if (dmg == 12)
	{
		std::cout << "MEDUSA USED GLARE!" << std::endl;
		std::cout << "Opponent was turned to stone!" << std::endl;
		dmg = 1000; //guarantees death
	}
	std::cout << "Medusa attacked for " << dmg << " points of damage!" << std::endl;
	return dmg;
}


/*****************************************************************
** Function: defend()
** Description: calculates damage taken
** Parameters: int
*****************************************************************/
int Medusa::defend(int atk) //1d6
{
	int def = 0;
	int dmg = 0;

	def = rand() % 6 + 1; //defense roll
	def += armor;
	std::cout << "Medusa blocked " << def << " points of damage!" << std::endl;
	dmg = atk - def; //calculating net damage
	if (dmg < 1) //no negative damage
	{
		dmg = 0; 
	}

	hp -= dmg; //subtracting dmg from hp

	std::cout << "Medusa took " << dmg << " points of damage!" << std::endl;
	std::cout << "Medusa's remaining health: " << hp << std::endl;

	return dmg;

}


/*****************************************************************
** Function: getType()
** Description: returns type of creature
** Parameters: none
*****************************************************************/
std::string Medusa::getType()
{
	return type;
}


/*****************************************************************
** Function: deathCheck()
** Description: determines if creature died
** Parameters: none
*****************************************************************/
bool Medusa::deathCheck()
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
