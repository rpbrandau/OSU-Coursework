/*****************************************************************
** Program Filename: frozenFoods.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for FrozenFoods class
*****************************************************************/
//#pragma once

#ifndef FROZENFOODS_HPP
#define FROZENFOODS_HPP
#include "space.hpp"

class FrozenFoods : public Space
{
private:
	bool icicle;
public:
	FrozenFoods();
	~FrozenFoods();
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
#endif // !FROZENFOODS_HPP
