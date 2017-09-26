/*****************************************************************
** Program Filename: entrance.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Entrance class
*****************************************************************/
//#pragma once

#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "space.hpp"

class Entrance : public Space
{
private:
	bool highFive;
public:
	Entrance();
	~Entrance();
	virtual std::string getDescription();
	virtual std::string setDescription();
	virtual std::string getRoomName();
	virtual void getExits();
	virtual void displayItems();
	virtual Item getItem(int x); //returns an item
	virtual void initializeItems();
	virtual void special();
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5, Space *p6);
	virtual void unhook();
};
#endif // !ENTRANCE_HPP
