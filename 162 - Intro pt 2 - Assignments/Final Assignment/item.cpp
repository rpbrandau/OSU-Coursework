/*****************************************************************
** Program Filename: item.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Item class
*****************************************************************/
//#include "stdafx.h"
#include "item.hpp"
#include <iostream>
#include <string>


/*****************************************************************
** Function: Item()
** Description: constructor
** Parameters: none
*****************************************************************/
Item::Item()
{
	name = "";
	itemDescription = "";
	price = 0;
}


/*****************************************************************
** Function: Item()
** Description: constructor
** Parameters: string, string, itn
*****************************************************************/
Item::Item(std::string n, std::string d, int p)
{
	name = n;
	itemDescription = d;
	price = p;
}


/*****************************************************************
** Function: ~Item()
** Description: Destructor
** Parameters: none
*****************************************************************/
Item::~Item()
{

}


/*****************************************************************
** Function: getItemDescription()
** Description: returns item's description
** Parameters: none
*****************************************************************/
std::string Item::getItemDescription()
{
	return itemDescription;
}


/*****************************************************************
** Function: setItemDescription()
** Description: sets an item's description
** Parameters: string
*****************************************************************/
void Item::setItemDescription(std::string d)
{
	itemDescription = d;
}


/*****************************************************************
** Function: getPrice()
** Description: returns item's price
** Parameters: none
*****************************************************************/
int Item::getPrice()
{
	return price;
}


/*****************************************************************
** Function: setPrice()
** Description: sets an item's price
** Parameters: int
*****************************************************************/
void Item::setPrice(int p)
{
	price = p;
}


/*****************************************************************
** Function: getName()
** Description: returns an item's name
** Parameters: none
*****************************************************************/
std::string Item::getName()
{
	return name;
}


/*****************************************************************
** Function: setName()
** Description: sets an item's name
** Parameters: string
*****************************************************************/
void Item::setName(std::string n)
{
	name = n;
}


/*
void Item::setStatus()
{
	if (this->pickedUp == false)
	{
		pickedUp = true;
	}
	else
	{
		pickedUp = false;
	}
}
*/
