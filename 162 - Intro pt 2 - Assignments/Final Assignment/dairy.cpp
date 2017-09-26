/*****************************************************************
** Program Filename: dairy.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Dairy class
*****************************************************************/
//#include "stdafx.h"
#include "dairy.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Dairy()
** Description: constructor
** Parameters: none
*****************************************************************/
Dairy::Dairy()
{
	roomName = "Udder Gifts";
	roomDescription = setDescription();
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	nw = NULL;
	sw = NULL;
	ne = NULL;
	se = NULL;
	initializeItems();
}


/*****************************************************************
** Function: ~Dairy()
** Description: Destructor
** Parameters: none
*****************************************************************/
Dairy::~Dairy()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Dairy::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Dairy::setDescription()
{
	std::string description;
	description = "Nestled at the bottom of some rolling green hills is a large barn. Gigantic cows are milling about...";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Dairy::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Dairy::initializeItems()
{
	a.setItemDescription("A glass container full of white liquid.");
	a.setName("Milk");
	a.setPrice(3);
	b.setItemDescription("Smells of unwashed feet. YUCK!");
	b.setName("Cheese");
	b.setPrice(5);
	c.setItemDescription("Milk with culture. Whatever that means.");
	c.setName("Sour Cream");
	c.setPrice(3);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void Dairy::displayItems()
{
	std::cout << "It appears that these items are in the room: " << std::endl;
	//std::cout << "Item 1: ";
	//std::cout << this->a.getName() << std::endl;
	std::cout << "Item 1 description: ";
	std::cout << this->a.getItemDescription() << std::endl;

	std::cout << "Item 2: ";
	//std::cout << this->b.getName() << std::endl;
	//std::cout << "Item 2 description: ";
	std::cout << this->b.getItemDescription() << std::endl;

	//std::cout << "Item 3: ";
	//std::cout << this->c.getName() << std::endl;
	std::cout << "Item 3 Description: ";
	std::cout << this->c.getItemDescription() << std::endl;
}


/*****************************************************************
** Function: getItem()
** Description: returns selected item
** Parameters: int
*****************************************************************/
Item Dairy::getItem(int x)
{
	if (x == 1)
	{
		return a;
	}
	if (x == 2)
	{
		return b;
	}
	if (x == 3)
	{
		return c;
	}
}


/*****************************************************************
** Function: special()
** Description: performs a special action, unique to the room
** Parameters: none
*****************************************************************/
void Dairy::special()
{
	if (swim == false)
	{
		std::cout << "Your trek through the Wastes almost gave you heatstroke. \nYou decide to take a dip in the river." << std::endl;
		swim = true;
	}
	else
	{
		std::cout << "You're not hot anymore, and the river left a weird residue on your skin." << std::endl;
		std::cout << "At least it was refreshing." << std::endl;
	}

}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Dairy::ptrSetup(Space *frozen, Space *bakery, Space *entrance, Space *canned)
{
	nw = frozen;
	south = bakery;
	west = canned;
	sw = entrance;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Dairy::getExits()
{
	if (this->north == NULL)
	{
		std::cout << "No exit to the North." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->north->getRoomName() << "*** to the NORTH." << std::endl;
	}
	if (this->ne == NULL)
	{
		std::cout << "No exit to the North East." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->ne->getRoomName() << "*** to the NORTH EAST." << std::endl;
	}
	if (this->east == NULL)
	{
		std::cout << "No exit to the East." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->east->getRoomName() << "*** to the EAST." << std::endl;
	}
	if (this->se == NULL)
	{
		std::cout << "No exit to the South East." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->se->getRoomName() << "*** to the SOUTH EAST." << std::endl;
	}

	if (this->south == NULL)
	{
		std::cout << "No exit to the South." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->south->getRoomName() << "*** to the SOUTH." << std::endl;
	}
	if (this->sw == NULL)
	{
		std::cout << "No exit to the South West." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->sw->getRoomName() << "*** to the SOUTH WEST." << std::endl;
	}
	if (this->west == NULL)
	{
		std::cout << "No exit to the West." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->west->getRoomName() << "*** to the WEST." << std::endl;
	}
	if (this->nw == NULL)
	{
		std::cout << "No exit to the North West." << std::endl;
	}
	else
	{
		std::cout << "You can see ***" << this->nw->getRoomName() << "*** to the NORTH WEST." << std::endl;
	}
}
