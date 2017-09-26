/*****************************************************************
** Program Filename: dairy.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Dairy class
*****************************************************************/
//#pragma once

#ifndef DAIRY_HPP
#define DAIRY_HPP
#include "space.hpp"

class Dairy : public Space
{
private:
	bool swim;
public:
	Dairy();
	~Dairy();
	virtual std::string getDescription();
	virtual std::string setDescription();
	virtual std::string getRoomName();
	virtual void getExits();
	virtual void displayItems();
	virtual Item getItem(int x); //returns an item
	virtual void initializeItems();
	virtual void special();
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4);
};
#endif // !DAIRY_HPP
