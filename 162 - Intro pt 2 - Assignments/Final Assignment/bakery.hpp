/*****************************************************************
** Program Filename: bakery.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Bakery class
*****************************************************************/
//#pragma once

#ifndef BAKERY_HPP
#define BAKERY_HPP
#include "space.hpp"

class Bakery : public Space
{
private:
	bool smell;
public:
	Bakery();
	~Bakery();
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
#endif // !BAKERY_HPP
