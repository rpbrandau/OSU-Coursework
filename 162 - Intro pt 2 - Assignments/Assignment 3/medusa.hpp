/*****************************************************************
** Program Filename: medusa.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: header file for Medusa class
*****************************************************************/
//#pragma once


#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib> //needed for rand


class Medusa : public Creature
{
private:

public:
	Medusa();
	~Medusa();
	int attack();
	int defend(int atk);
	std::string getType();
	bool deathCheck();


};


#endif
