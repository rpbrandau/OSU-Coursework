/*****************************************************************
** Program Filename: blueMen.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: header file for BlueMen class
*****************************************************************/
//#pragma once

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib> //needed for rand

class BlueMen : public Creature
{
private:


public:
	BlueMen();
	~BlueMen();

	int attack();
	int defend(int atk);
	std::string getType();
	bool deathCheck();


};



#endif
