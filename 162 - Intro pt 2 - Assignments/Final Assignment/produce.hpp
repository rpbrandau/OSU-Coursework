/*****************************************************************
** Program Filename: produce.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Produce class
*****************************************************************/
//#pragma once

#ifndef PRODUCE_HPP
#define PRODUCE_HPP
#include "space.hpp"

class Produce : public Space
{
private:
	bool sprinklers;
public:
	Produce();
	~Produce();
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
#endif // !PRODUCE_HPP
