/*****************************************************************
** Program Filename: harryPotter.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: header file for HarryPotter class
*****************************************************************/
//#pragma once

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib> //needed for rand

class HarryPotter : public Creature
{
private:
	bool revive = true;

public:
	HarryPotter();
	~HarryPotter();

	int attack();
	int defend(int atk);
	std::string getType();
	bool deathCheck();


};



#endif
