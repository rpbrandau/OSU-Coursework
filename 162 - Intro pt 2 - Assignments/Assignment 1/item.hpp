/*****************************************************************
** Program Filename: item.hpp
** Author: Riley Brandau
** Date: 6/22/16
** Description: header file for Item class
*****************************************************************/
//#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item
{
private:
	std::string itemName = "";
	std::string unit = "";
	int numToBuy = 0;
	double unitPrice = 0.0;
	double subTotal = 0.0;
public:
	Item();
	std::string getName();
	std::string getUnit();
	int getNumToBuy();
	double getUnitPrice();
	double getSubTotal();

	void setItemName(std::string n);
	void setUnit(int u);
	void setNumToBuy(int b);
	void setUnitPrice(double p);

};

#endif // !ITEM_HPP
