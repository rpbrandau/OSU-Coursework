/*****************************************************************
** Program Filename: item.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Item class
*****************************************************************/
//#pragma once

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>


class Item
{
private:
	//bool pickedUp;
	std::string name;
	std::string itemDescription;
	int price;

public:
	Item();
	Item(std::string n, std::string d, int p);
	~Item();
	std::string getItemDescription();
	void setItemDescription(std::string d);
	int getPrice();
	std::string getName();
	void setStatus();
	void setPrice(int p);
	void setName(std::string n);

};
#endif // !ITEM_HPP
