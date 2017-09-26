/*****************************************************************
** Program Filename: produce.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Produce class
*****************************************************************/
//#include "stdafx.h"
#include "produce.hpp"


/*****************************************************************
** Function: Produce()
** Description: constructor
** Parameters: none
*****************************************************************/
Produce::Produce()
{
	roomName = "The Living Earth";
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
	sprinklers = false;
}


/*****************************************************************
** Function: ~Produce()
** Description: Destructor
** Parameters: none
*****************************************************************/
Produce::~Produce()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Produce::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Produce::setDescription()
{
	std::string description;
	description = "You push aside some foliage, revealing a lush valley full of abnormally large fruits and vegetables.";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Produce::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Produce::initializeItems()
{
	a.setItemDescription("Huge head of leafy greens.");
	a.setName("Lettuce");
	a.setPrice(2);
	b.setItemDescription("An different varieties of Red, Green, and Yellow fruit. Good for eating on the go.");
	b.setName("An apple");
	b.setPrice(2);
	c.setItemDescription("Small, bright red, yellow, and orange. Do not touch your eyes after handling!");
	c.setName("Chilies");
	c.setPrice(2);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void Produce::displayItems()
{
	std::cout << "It appears that these items are in the room: " << std::endl;
	//std::cout << "Item 1: ";
	//std::cout << this->a.getName() << std::endl;
	std::cout << "Item 1 description: ";
	std::cout << this->a.getItemDescription() << std::endl;

	//std::cout << "Item 2: ";
	//std::cout << this->b.getName() << std::endl;
	std::cout << "Item 2 description: ";
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
Item Produce::getItem(int x)
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
void Produce::special()
{
	std::cout << "You flip a conspicuous switch on the ground in front of you..." << std::endl;
	if (sprinklers == false)
	{
		std::cout << "A fine mist descends from the sky, covering everything in dew drops." << std::endl;
		sprinklers = true;
	}
	else
	{
		std::cout << "The sun shines more intensely, banishing the mist." << std::endl;
		sprinklers = false;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Produce::ptrSetup(Space *butcher, Space *frozen, Space *canned, Space *entrance)
{
	south = butcher;
	ne = frozen;
	east = canned;
	se = entrance;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Produce::getExits()
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
