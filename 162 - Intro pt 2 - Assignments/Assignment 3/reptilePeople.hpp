/*****************************************************************
** Program Filename: reptilePeople.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: header file for ReptilePeople class
*****************************************************************/
//#pragma once


#ifndef REPTILEPEOPLE_HPP
#define REPTILEPEOPLE_HPP
#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib> //needed for rand


class ReptilePeople : public Creature
{
private:

public:
	ReptilePeople();
	~ReptilePeople();

	int attack();
	int defend(int atk);
	std::string getType();
	bool deathCheck();


};


#endif
