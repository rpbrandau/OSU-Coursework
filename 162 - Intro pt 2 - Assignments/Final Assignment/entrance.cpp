/*****************************************************************
** Program Filename: entrance.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Entrance class
*****************************************************************/
//#include "stdafx.h"
#include "entrance.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Entrance()
** Description: constructor
** Parameters: none
*****************************************************************/
Entrance::Entrance()
{
	roomName = "The Gate";
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
	highFive = false;
}


/*****************************************************************
** Function: ~Entrance()
** Description: Destructor
** Parameters: none
*****************************************************************/
Entrance::~Entrance()
{

}


/*****************************************************************
** Function: getDescription()
** Description: Returns the room's description
** Parameters: none
*****************************************************************/
std::string Entrance::getDescription()
{
	return roomDescription;
}


/*****************************************************************
** Function: setDescription()
** Description: used for setting room's description
** Parameters: none
*****************************************************************/
std::string Entrance::setDescription()
{
	std::string description;
	description = "An imposing figure guards the gate. It watches you intently but does not move to barr your way.";
	return description;
}


/*****************************************************************
** Function: getRoomName()
** Description: returns the room's name
** Parameters: none
*****************************************************************/
std::string Entrance::getRoomName()
{
	return roomName;
}


/*****************************************************************
** Function: initializeItems()
** Description: creates the items in the room
** Parameters: none
*****************************************************************/
void Entrance::initializeItems()
{
	a.setItemDescription("Sweet. Pink. Pliable. Good for chewing on.");
	a.setName("Gum");
	a.setPrice(1);
	b.setItemDescription("Chewy caramel covered in Chocolate.");
	b.setName("100 Grand");
	b.setPrice(1);
	c.setItemDescription("Small colorful chewy bits of candy.");
	c.setName("Skittles");
	c.setPrice(1);
}


/*****************************************************************
** Function: displayItems()
** Description: shows the items in the room
** Parameters: none
*****************************************************************/
void Entrance::displayItems()
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
Item Entrance::getItem(int x)
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
void Entrance::special()
{
	std::cout << "You look at the Gatekeeper. You can't tell if it is looking back at you or not." << std::endl;
	std::cout << "Its head is shrowded in a cloak, both hands are outstreatched as if waiting to receive something." << std::endl;
	if (highFive == false)
	{
		std::cout << "You slowly approach the figure, and after you decide it isn't going to do anything, \nyou slap it's hand as if giving it a high five." << std::endl;
		std::cout << "Its head snaps to look you directly in the eyes and a ghastly voice eminates from where its mouth should be:\nDO NOT TEST ME, YOUNG ONE. I AM THE KEEPER." << std::endl;
		std::cout << "THE NEXT TIME YOU TOUCH ME, I WILL REQUIRE PAYMENT." << std::endl;
		highFive = true;
	}
	else
	{
		std::cout << "... probably best to leave the Keeper alone." << std::endl;
	}
}


/*****************************************************************
** Function: ptrSetup()
** Description: handles the setting of room pointers
** Parameters: Space pointers
*****************************************************************/
void Entrance::ptrSetup(Space *outside, Space *butcher, Space *bakery, Space *produce, Space *canned, Space *dairy)
{
	south = outside;
	west = butcher;
	east = bakery;
	nw = produce;
	north = canned;
	ne = dairy;
}


/*****************************************************************
** Function: unhook()
** Description: sets Entrance's south pointer to null
** Parameters: none
*****************************************************************/
void Entrance::unhook()
{
	this->south = NULL;
}


/*****************************************************************
** Function: getExits()
** Description: shows where the player can move (room links)
** Parameters: none
*****************************************************************/
void Entrance::getExits()
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
