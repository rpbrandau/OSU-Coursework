/*****************************************************************
** Program Filename: harryPotter.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: source file for HarryPotter class
*****************************************************************/
//#include "stdafx.h"
#include "harryPotter.hpp"


/*****************************************************************
** Function: HarryPotter()
** Description: constructor
** Parameters: none
*****************************************************************/
HarryPotter::HarryPotter()
{
	armor = 0;
	hp = 10;
	type = "Harry Potter";
}


/*****************************************************************
** Function: ~HarryPotter()
** Description: destructor
** Parameters: none
*****************************************************************/
HarryPotter::~HarryPotter()
{

}


/*****************************************************************
** Function: attack()
** Description: calculates damage dealt
** Parameters: none
*****************************************************************/
int HarryPotter::attack() //2d6
{
	int dmg = 0;
	for (int i = 0; i < 2; i++)
	{
		dmg += rand() % 6 + 1; //will return 2-12
	}
	std::cout << "Harry Potter attacked for " << dmg << " points of damage!" << std::endl;
	return dmg;
}


/*****************************************************************
** Function: defend()
** Description: calculates damage taken
** Parameters: int
*****************************************************************/
int HarryPotter::defend(int atk) //2d6. upon taking 10dmg, revive w/ 10hp once.
{
	int def = 0;
	int dmg = 0;

	for (int i = 0; i < 2; i++) //calculating defense
	{
		def += rand() % 6 + 1;
	}
	def += armor; //adding armor to defense roll
	std::cout << "Harry Potter blocked " << def << " points of damage!" << std::endl;
	dmg = atk - def; //calculating net damage
	if (dmg < 1) //no negative damage
	{
		dmg = 0;
	}

	hp -= dmg; //subtracting dmg from hp
	std::cout << "Harry Potter took " << dmg << " points of damage!" << std::endl;
	if (hp < 1 && revive == true)
	{
		hp = 10;
		std::cout << "You're a wizard, Harry!" << std::endl;
		std::cout << "(Harry has been revived)" << std::endl;
		revive = false;
	}
	
	std::cout << "Harry Potter's remaining health: " << hp << std::endl;

	return dmg;
}


/*****************************************************************
** Function: getType()
** Description: returns type of creature
** Parameters: none
*****************************************************************/
std::string HarryPotter::getType()
{
	return type;
}


/*****************************************************************
** Function: deathCheck()
** Description: determines if creature died
** Parameters: none
*****************************************************************/
bool HarryPotter::deathCheck()
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
