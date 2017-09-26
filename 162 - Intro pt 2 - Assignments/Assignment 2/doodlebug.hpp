/*****************************************************************
** Program Filename: doodlebug.hpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: headerfile for doodlebug class
*****************************************************************/
//#pragma once

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "critter.hpp"


class Doodlebug : public Critter
{
private:
	/*
	int x;
	int y;
	int breedCounter;
	int eatCounter; //dies if reaches 3
	bool eat;
	bool die;
	*/
public:
	Doodlebug();
	Doodlebug(int x, int y);
	int virtual move();
	bool virtual breed();
	bool virtual eat();
	bool virtual death();
	char virtual critterType();
};
#endif // !DOODLEBUG_H
