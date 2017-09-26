/*****************************************************************
** Program Filename: cannedGoods.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for CannedGoods class
*****************************************************************/
//#pragma once

#ifndef CANNEDGOODS_HPP
#define CANNEDGOODS_HPP
#include "space.hpp"

class CannedGoods : public Space
{
private:
	bool shout;
public:
	CannedGoods();
	~CannedGoods();
	virtual std::string getDescription();
	virtual std::string setDescription();
	virtual std::string getRoomName();
	virtual void getExits();
	virtual void displayItems();
	virtual Item getItem(int x); //returns an item
	virtual void initializeItems();
	virtual void special();
	virtual void ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5, Space *p6);
};
#endif // !CANNEDGOODS_HPP
