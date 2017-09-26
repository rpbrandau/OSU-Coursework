/*****************************************************************
** Program Filename: outside.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Outside class
*****************************************************************/
//#include "stdafx.h"
#include "outside.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Outside()
** Description: constructor
** Parameters: none
*****************************************************************/
Outside::Outside()
{
	roomName = "The Wastelands";
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
	//dog = false;
	dragon = false;
}


/*****************************************************************
** Function: ~Outside()
** Description: Destructor
** Parameters: none
*****************************************************************/
Outside::~Outside()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Outside::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Outside::setDescription()
{
	std::string description;
	description = "The sun is exceptionally bright, and the earth here has been blackened by the heat.";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Outside::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Outside::initializeItems()
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
void Outside::displayItems()
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
Item Outside::getItem(int x)
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
void Outside::special()
{
	std::cout << "You shield your eyes from the sun and gaze up at the brilliantly blue sky..." << std::endl;
	if (dragon == false)
	{
		std::cout << "A large shadow swoops across your field of vision..." << std::endl;
		std::cout << "Moments later you hear an earsplitting screech, but whatever cast the shadow has moved on." << std::endl;
		dragon = true;
	}
	else
	{
		std::cout << "Something catches your eye on the horizon... It appears to be a large plume of fire!" << std::endl;
		std::cout << "You decide it would be best not to stay here for too long..." << std::endl;
		dragon = false;
	}

}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Outside::ptrSetup(Space *home, Space *entrance)
{
	north = entrance;
	south = home;
}


/*****************************************************************
** Function: unhook()
** Description: sets outside's north & south pointer to null
** Parameters: none
*****************************************************************/
void Outside::unhook()
{
	this->north = NULL;
	this->south = NULL;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Outside::getExits()
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
