/*****************************************************************
** Program Filename: space.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Space class (abstract base class)
*****************************************************************/
//#pragma once

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>
#include "item.hpp"

class Space
{
protected:
	Space *north, *ne, *east, *se, *south, *sw, *west, *nw; //8 pointers to spaces. Not all will be used.
	std::string roomDescription;
	std::string roomName;
	Item a, b, c; //reserving space for 3 items
	
public:
	Space();
	virtual std::string getDescription() = 0;
	virtual std::string getRoomName() = 0;
	virtual std::string setDescription() = 0;
	virtual void getExits();
	virtual void displayItems() = 0;
	virtual Item getItem(int x) = 0; //returns an item
	virtual void initializeItems() = 0;
	virtual void special() = 0;
	virtual void ptrSetup(Space *p1);
	virtual void ptrSetup(Space *p1, Space *p2);
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3);
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4);
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5, Space *p6);
	virtual void unhook();

	virtual Space* getNorth();
	virtual Space* getNE();
	virtual Space* getEast();
	virtual Space* getSE();
	virtual Space* getSouth();
	virtual Space* getSW();
	virtual Space* getWest();
	virtual Space* getNW();
};

#endif // !SPACE_HPP
