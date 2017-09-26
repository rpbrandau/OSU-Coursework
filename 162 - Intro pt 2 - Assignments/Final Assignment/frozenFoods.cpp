/*****************************************************************
** Program Filename: frozenFoods.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for FrozenFoods class
*****************************************************************/
//#include "stdafx.h"
#include "frozenFoods.hpp"
#include "item.hpp"


/*****************************************************************
** Function: FrozenFoods()
** Description: constructor
** Parameters: none
*****************************************************************/
FrozenFoods::FrozenFoods()
{
	roomName = "The Fridgid Caverns of Teevee Dinneria";
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
	icicle = false;
}


/*****************************************************************
** Function: ~FrozenFoods()
** Description: Destructor
** Parameters: none
*****************************************************************/
FrozenFoods::~FrozenFoods()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string FrozenFoods::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string FrozenFoods::setDescription()
{
	std::string description;
	description = "As you set foot inside the caverns, you are chilled to the bone. /n Probably best not to stay here for too long... ";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string FrozenFoods::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void FrozenFoods::initializeItems()
{
	a.setItemDescription("Picture of a lumberjack wolfing down grey meat and mashed potatoes.");
	a.setName("Hungry Man Dinner");
	a.setPrice(5);
	b.setItemDescription("Flakey dough that gives way to a sweet gooey fruit center.");
	b.setName("Pie");
	b.setPrice(10);
	c.setItemDescription("Layered pasta. Filled with meat and cheese.");
	c.setName("Lasagna");
	c.setPrice(10);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void FrozenFoods::displayItems()
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
Item FrozenFoods::getItem(int x)
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
void FrozenFoods::special()
{
	
	if (icicle == false)
	{
		std::cout << "You see a large icicle sticking up out of the ground and wonder if you could break it off..." << std::endl;
		std::cout << "You give the icicle a few good kicks, and it snaps free from its base and hits the floor with a THUD." << std::endl;
		std::cout << "That was fun!" << std::endl;
		icicle = true;
	}
	else
	{
		std::cout << "The only other icicles you see are much too large to break." << std::endl;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void FrozenFoods::ptrSetup(Space *produce, Space *canned, Space *dairy)
{
	south = canned;
	sw = produce;
	se = dairy;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void FrozenFoods::getExits()
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
