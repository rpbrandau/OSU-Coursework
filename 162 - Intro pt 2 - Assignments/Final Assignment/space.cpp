/*****************************************************************
** Program Filename: space.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Space class
*****************************************************************/
//#include "stdafx.h"
#include "space.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Space()
** Description: constructor
** Parameters: none
*****************************************************************/
Space::Space()
{

}

/*****************************************************************
** Function: getExits()
** Description: displays available exits for player to take
** Parameters: none
*****************************************************************/
void Space::getExits()
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


/*****************************************************************
** Function: ptrSetup()
** Description: functions that link the rooms together
** Parameters: pointers to space (1 to 6 depending on room)
*****************************************************************/

void Space::ptrSetup(Space *ptr)
{

}
void Space::ptrSetup(Space *p1, Space *p2)
{

}
void Space::ptrSetup(Space *p1, Space *p2, Space *p3)
{

}
void Space::ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4)
{

}
void Space::ptrSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5, Space *p6)
{

}


/*****************************************************************
** Function: unhook()
** Description: unlinks rooms
** Parameters: none
*****************************************************************/
void Space::unhook()
{

}


/*****************************************************************
** Function: getNorth() (or other direction)
** Description: returns pointer of that direction
** Parameters: none
*****************************************************************/
Space* Space::getNorth()
{
	return this->north;
}
Space* Space::getNE()
{
	return this->ne;
}
Space* Space::getEast()
{
	return this->east;
}
Space* Space::getSE()
{
	return this->se;
}
Space* Space::getSouth()
{
	return this->south;
}
Space* Space::getSW()
{
	return this->sw;
}
Space* Space::getWest()
{
	return this->west;
}
Space* Space::getNW()
{
	return this->nw;
}
