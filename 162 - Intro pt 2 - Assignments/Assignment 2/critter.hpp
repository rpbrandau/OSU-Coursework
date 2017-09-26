/*****************************************************************
** Program Filename: critter.hpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: headerfile for critter class
*****************************************************************/
//#pragma once

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
protected:
	int x;
	int y;
	int breedCounter;
	int eatCounter;
	//bool eat;
	bool die;

public:
	Critter();
	int virtual move();
	bool virtual breed();
	bool virtual eat();
	bool virtual death();
	char virtual critterType();

};
#endif // !CRITTER_H
