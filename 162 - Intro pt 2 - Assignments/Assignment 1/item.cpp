/*****************************************************************
** Program Filename: item.cpp
** Author: Riley Brandau
** Date: 6/22/16
** Description: Source file for item class functions
*****************************************************************/
//#include "stdafx.h"
#include "item.hpp"


/*****************************************************************
** Function: Item()
** Description: Constructor
*****************************************************************/
Item::Item()
{
	itemName = "";
	unit = "";
	numToBuy = 0;
	unitPrice = 0.0;
	subTotal = 0.0;
}



/*****************************************************************
** Function: getName()
** Description: get method
*****************************************************************/
std::string Item::getName()
{
	return itemName;
}



/*****************************************************************
** Function: getUnit()
** Description: get method
*****************************************************************/
std::string Item::getUnit()
{
	return unit;
}



/*****************************************************************
** Function: getNumToBuy()
** Description: get method
*****************************************************************/
int Item::getNumToBuy()
{
	return numToBuy;
}



/*****************************************************************
** Function: getUnitPrice()
** Description: get method
*****************************************************************/
double Item::getUnitPrice()
{
	return unitPrice;
}



/*****************************************************************
** Function: setItemName()
** Description: set method
*****************************************************************/
void Item::setItemName(std::string n)
{
	itemName = n;
}



/*****************************************************************
** Function: setUnit()
** Description: set method
*****************************************************************/
void Item::setUnit(int u)
{
	if (u == 1)
	{
		unit = "Box";
	}
	else if (u == 2)
	{
		unit = "Ounce";
	}
	else if (u == 3)
	{
		unit = "Pound";
	}
	else if (u == 4)
	{
		unit = "Package";
	}
	else if (u == 10)
	{
		unit = "Deleted";
	}
	else
	{
		unit = "Other";
	}
}


/*****************************************************************
** Function: setUnitPrice()
** Description: set method
*****************************************************************/
void Item::setUnitPrice(double p)
{
	unitPrice = p;
}



/*****************************************************************
** Function: setNumToBuy()
** Description: set method
*****************************************************************/
void Item::setNumToBuy(int n)
{
	numToBuy = n;
}



/*****************************************************************
** Function: getSubTotal()
** Description: get method that calculates an item's subtotal
*****************************************************************/
double Item::getSubTotal()
{
	subTotal = unitPrice * numToBuy;
	return subTotal;
}
