/*****************************************************************
** Program Filename: bakery.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Bakery class
*****************************************************************/
//#include "stdafx.h"
#include "bakery.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Bakery()
** Description: constructor
** Parameters: none
*****************************************************************/
Bakery::Bakery()
{
	roomName = "Doughopolis";
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
** Function: ~Bakery()
** Description: Destructor
** Parameters: none
*****************************************************************/
Bakery::~Bakery()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Bakery::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Bakery::setDescription()
{
	std::string description;
	description = "*The sweet smell of baked goods wafts through the air \n You have arrived in Doughopolis.";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Bakery::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Bakery::initializeItems()
{
	a.setItemDescription("A sweet and soft bread. Perfect for dipping in olive oil and balsamic vinegar.");
	a.setName("French Bread");
	a.setPrice(3);
	b.setItemDescription("Soft dough spun in a circle, covered in a sweet glaze and topped with nuts.");
	b.setName("Honey Bun");
	b.setPrice(5);
	c.setItemDescription("Bread with a hard outer crust with a sour, savory scent.");
	c.setName("Sourdough Round");
	c.setPrice(3);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void Bakery::displayItems()
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
Item Bakery::getItem(int x)
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
void Bakery::special()
{
	if (smell == false)
	{
		std::cout << "You breathe in deeply, smelling the sweet air. Your mouth begins to salivate." << std::endl;
		smell = true;
	}
	else
	{
		std::cout << "You're slightly dizzy from taking such a deep breath. You wipe the drool from your mouth." << std::endl;
		std::cout << "..." << std::endl;
		std::cout << "..." << std::endl;
		std::cout << "..." << std::endl;
		std::cout << "After a moments rest, you no longer feel dizzy." << std::endl;
		smell = false;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Bakery::ptrSetup(Space *entrance, Space *dairy, Space *canned)
{
	north = dairy;
	west = entrance;
	nw = canned;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Bakery::getExits()
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
