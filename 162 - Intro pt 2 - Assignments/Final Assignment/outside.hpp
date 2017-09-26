/*****************************************************************
** Program Filename: outside.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Outside class
*****************************************************************/
//#pragma once

#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP
#include "space.hpp"

class Outside : public Space
{
private:
	//bool dog;
	bool dragon;
public:
	Outside();
	~Outside();
	virtual std::string getDescription();
	virtual std::string setDescription();
	virtual std::string getRoomName();
	virtual void getExits();
	virtual void displayItems();
	virtual Item getItem(int x); //returns an item
	virtual void initializeItems();
	virtual void special();
	virtual void ptrSetup(Space *p1, Space *p2);
	virtual void unhook();
};
#endif // !OUTSIDE_HPP
