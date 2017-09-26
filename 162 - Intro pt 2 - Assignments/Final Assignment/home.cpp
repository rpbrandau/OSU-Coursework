/*****************************************************************
** Program Filename: home.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Home class
*****************************************************************/
//#include "stdafx.h"
#include "home.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Home()
** Description: constructor
** Parameters: none
*****************************************************************/
Home::Home()
{
	roomName = "Home";
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
	lamp = false;
}


/*****************************************************************
** Function: ~Home()
** Description: Destructor
** Parameters: none
*****************************************************************/
Home::~Home()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Home::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Home::setDescription()
{
	std::string description;
	description = "This is your home. You feel comfortable here.";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Home::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Home::initializeItems()
{
	a.setItemDescription("");
	a.setName("");
	a.setPrice(0);
	b.setItemDescription("");
	b.setName("");
	b.setPrice(0);
	c.setItemDescription("");
	c.setName("");
	c.setPrice(0);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void Home::displayItems()
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
Item Home::getItem(int x)
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
void Home::special()
{
	std::cout << "You walk over to the table where the lamp is resting." << std::endl;
	if (lamp == false)
	{
		std::cout << "You fumble under the lamp shade, trying to find it's switch." << std::endl;
		std::cout << "A few seconds later you find it and switch it on." << std::endl;
		std::cout << "The room is bathed in a soft warm light." << std::endl;
		lamp = true;
	}
	else
	{
		std::cout << "You fumble under the lamp shade, trying to find it's switch." << std::endl;
		std::cout << "A few seconds later you find it and switch it off." << std::endl;
		std::cout << "The room goes dark." << std::endl;
		lamp = false;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Home::ptrSetup(Space *outside)
{
	north = outside;
}


/*****************************************************************
** Function: unhook()
** Description: sets Home's north pointer to null
** Parameters: none
*****************************************************************/
void Home::unhook()
{
	this->north = NULL;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Home::getExits()
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
