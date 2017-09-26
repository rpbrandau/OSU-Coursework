/*****************************************************************
** Program Filename: creature.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: header file for Creature class
*****************************************************************/
//#pragma once

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>

class Creature
{
protected:
	int armor;
	int hp;
	std::string type;


public:
	Creature();
	~Creature();

	virtual int attack() = 0;
	virtual int defend(int) = 0;
	virtual std::string getType() = 0;
	virtual bool deathCheck() = 0;

};

#endif // !CREATURE_HPP

