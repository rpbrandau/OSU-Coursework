/*****************************************************************
** Program Filename: home.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Home class
*****************************************************************/
//#pragma once

#ifndef HOME_HPP
#define HOME_HPP
#include "space.hpp"

class Home : public Space
{
private:
	bool lamp;
public:
	Home();
	~Home();
	virtual std::string getDescription();
	virtual std::string setDescription();
	virtual std::string getRoomName();
	virtual void getExits();
	virtual void displayItems();
	virtual Item getItem(int x); //returns an item
	virtual void initializeItems();
	virtual void special();
	virtual void ptrSetup(Space *p1);
	virtual void unhook();
};
#endif // !HOME_HPP
