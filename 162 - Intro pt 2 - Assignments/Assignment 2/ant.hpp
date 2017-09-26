/*****************************************************************
** Program Filename: ant.hpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: headerfile for ant class
*****************************************************************/
#pragma once

#ifndef ANT_HPP
#define ANT_HPP
#include "critter.hpp"

class Ant : public Critter
{
private:
	/*
	int x;
	int y;
	int breedCounter;
	int eatCounter; //dies if reaches 10
	bool eat;
	bool die;
	*/

public:
	Ant();
	Ant(int x, int y);
	int virtual move();
	bool virtual breed();
	bool virtual eat();
	bool virtual death();
	char virtual critterType();
};
#endif // !ANT_H

