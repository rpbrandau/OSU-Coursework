/*****************************************************************
** Program Filename: cannedGoods.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for CannedGoods class
*****************************************************************/
//#include "stdafx.h"
#include "cannedGoods.hpp"
#include "item.hpp"
#include <stdlib.h>

/*****************************************************************
** Function: CannedGoods()
** Description: constructor
** Parameters: none
*****************************************************************/
CannedGoods::CannedGoods()
{
	roomName = "Tomb of the Un-Perished";
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
	shout = false;
}


/*****************************************************************
** Function: ~CannedGoods()
** Description: Destructor
** Parameters: none
*****************************************************************/
CannedGoods::~CannedGoods()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string CannedGoods::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string CannedGoods::setDescription()
{
	std::string description;
	description = "A staleness permiates the air. As you look around, you notice that everything is contained in tiny cans.";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string CannedGoods::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void CannedGoods::initializeItems()
{
	a.setItemDescription("This can has a picture of a green bean.");
	a.setName("Green Beans");
	a.setPrice(2);
	b.setItemDescription("This can has a picture of a tomato.");
	b.setName("Stewed Tomatoes");
	b.setPrice(2);
	c.setItemDescription("This can has a picture of what looks like a bloody heart?");
	c.setName("Beets");
	c.setPrice(2);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void CannedGoods::displayItems()
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
Item CannedGoods::getItem(int x)
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
void CannedGoods::special()
{
	int x = 0;
	if (shout == false)
	{
		std::cout << "You look around to make sure no one is there, and then you take in a deep breath and shout:" << std::endl;
		x = rand() % 4;
		if (x == 0)
		{
			std::cout << "'ECHO!'" << std::endl;
			std::cout << "It bounces off of the tomb's walls: ECHOECHoECHoeEchoecho..." << std::endl;
		}
		if (x == 1)
		{
			std::cout << "'YODELEHIHOO'" << std::endl;
			std::cout << "It reverberates off the tomb's walls: YODELEHIHOOYODELEHIhooHiHoohihoo" << std::endl;
		}
		if (x == 2)
		{
			std::cout << "'I LOVE PANCAKES'" << std::endl;
			std::cout << "It bounces off the tomb's walls: ILOVEPANCAKESCAKESCAKesCakesakes" << std::endl;
		}
		if (x == 3)
		{
			std::cout << "'HELLO'" << std::endl;
			std::cout << "It reverberates off the tomb's walls: HELLOELLOELLoello" << std::endl;
			std::cout << "Then from the depths of the tomb, you hear 'HI'" << std::endl;
			std::cout << "I should probably get out of here..." << std::endl;
		}
		shout = true;
	}
	else
	{
		std::cout << "You need to catch your breath before shouting again." << std::endl;
		shout = false;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void CannedGoods::ptrSetup(Space *frozen, Space *produce, Space *dairy, Space *bakery, Space *entrance, Space *butcher)
{
	north = frozen;
	west = produce;
	east = dairy;
	south = entrance;
	sw = butcher;
	se = bakery;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void CannedGoods::getExits()
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
