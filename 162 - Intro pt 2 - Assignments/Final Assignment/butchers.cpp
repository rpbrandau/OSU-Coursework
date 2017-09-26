/*****************************************************************
** Program Filename: butchers.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Butchers class
*****************************************************************/
//#include "stdafx.h"
#include "butchers.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Butchers()
** Description: constructor
** Parameters: none
*****************************************************************/
Butchers::Butchers()
{
	roomName = "The Butcher's Block";
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
	talk = false;
}


/*****************************************************************
** Function: ~Butchers()
** Description: Destructor
** Parameters: none
*****************************************************************/
Butchers::~Butchers()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Butchers::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Butchers::setDescription()
{
	std::string description;
	description = "You push aside a drape, revealing a grinning fat man in a blood stained apron. He licks his lips...";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Butchers::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Butchers::initializeItems()
{
	a.setItemDescription("Various ground meats stuffed inside an animal's intestine...");
	a.setName("Sausage");
	a.setPrice(4);
	b.setItemDescription("A giant cut of red, bloody meat, marbled with fat");
	b.setName("Steak");
	b.setPrice(10);
	c.setItemDescription("Appears to be some sort of bird meat. Feathers have been plucked.");
	c.setName("Chicken Thighs");
	c.setPrice(6);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void Butchers::displayItems()
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
	std::cout << std::endl;
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
Item Butchers::getItem(int x)
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
void Butchers::special()
{
	std::cout << "You approach the grinning butcher..." << std::endl;
	if (talk == false)
	{
		std::cout << "You: H..hello?" << std::endl;
		std::cout << "Butcher: *stares back at you, unblinking." << std::endl;
		std::cout << "This guy gives you the creeps!" << std::endl;
		talk = true;
	}
	else
	{
		std::cout << "You decide not to waste your breath." << std::endl;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Butchers::ptrSetup(Space *produce, Space *canned, Space *entrance)
{
	north = produce;
	ne = canned;
	east = entrance;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Butchers::getExits()
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
