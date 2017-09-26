/*****************************************************************
** Program Filename: gollum.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: header file for Gollum class
*****************************************************************/
//#pragma once

#ifndef GOLLUM_HPP
#define GOLLUM_HPP
#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib> //needed for rand

class Gollum : public Creature
{
private:

public:
	Gollum();
	~Gollum();
	int attack();
	int defend(int atk);
	std::string getType();
	bool deathCheck();

};


#endif
