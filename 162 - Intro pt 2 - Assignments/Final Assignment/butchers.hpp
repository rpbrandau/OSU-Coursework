/*****************************************************************
** Program Filename: butchers.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Butchers class
*****************************************************************/
//#pragma once

#ifndef BUTCHERS_HPP
#define BUTCHERS_HPP
#include "space.hpp"

class Butchers : public Space
{
private:
	bool talk;
public:
	Butchers();
	~Butchers();
	virtual std::string getDescription();
	virtual std::string setDescription();
	virtual std::string getRoomName();
	virtual void getExits();
	virtual void displayItems();
	virtual Item getItem(int x); //returns an item
	virtual void initializeItems();
	virtual void special();
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3);
};
#endif // !BUTCHERS_HPP
