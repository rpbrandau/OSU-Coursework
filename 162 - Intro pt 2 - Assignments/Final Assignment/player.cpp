/*****************************************************************
** Program Filename: player.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Source for Player class
*****************************************************************/
//#include "stdafx.h"
#include "player.hpp"
#include "space.hpp"
#include "item.hpp"


/*****************************************************************
** Function: Player()
** Description: constructor
** Parameters: none
*****************************************************************/
Player::Player()
{
	wallet = 20;
	itemCount = 0;
	initializeList();
	initializeBag();
}


/*****************************************************************
** Function: ~Player()
** Description: Destructor
** Parameters: none
*****************************************************************/
Player::~Player()
{

}


/*****************************************************************
** Function: throwItem()
** Description: removes an item from inventory
** Parameters: none
*****************************************************************/
void Player::throwItem()
{
	int c;
	std::string tempName = "";
	std::cout << "Which item would you like to throw?" << std::endl;
	displayBag();
	std::cin >> c;
	itemBag[c-1].setPrice(0);
	tempName = itemBag[c - 1].getName();
	itemBag[c-1].setName("");
	itemBag[c-1].setItemDescription("");
	if (itemCount < 1)
	{
		itemCount = 0;
	}
	else
	{
		itemCount--;
	}
	std::cout << "**You threw " << tempName << " on the ground**" << std::endl;
}


/*****************************************************************
** Function: searchRoom()
** Description: prints out the rooms name, description, and items
** Parameters: pointer to Space
*****************************************************************/
void Player::searchRoom(Space *room)
{
	std::cout << "Current room: ";
	std::cout << room->getRoomName() << std::endl;
	std::cout << std::endl;
	std::cout << "Room description: ";
	std::cout << room->getDescription() <<std::endl;
	std::cout << std::endl;
	room->displayItems();
}


/*****************************************************************
** Function: addItem()
** Description: adds an item to inventory
** Parameters: pointer to Space
*****************************************************************/
void Player::addItem(Space *ptr)
{
	if (itemCount > 5)
	{
		std::cout << "Bag is full." << std::endl;
	}
	else
	{
		Item tempItem;
		int c = 0;

		ptr->displayItems();
		while (c != 4)
		{
			std::cout << "1 = Item 1 \n2 = Item 2\n3 = Item 3\n4 = Exit" << std::endl;
			std::cin >> c;
			if (c == 1 || c == 2 || c == 3)
			{
				tempItem = ptr->getItem(c);
				itemBag[itemCount].setPrice(tempItem.getPrice());
				itemBag[itemCount].setItemDescription(tempItem.getItemDescription());
				itemBag[itemCount].setName(tempItem.getName());
				itemCount++;
				std::cout << "Item added to bag." << std::endl;
			}
			else
			{
				std::cout << "Closing bag." << std::endl;
			}
		}
	}
} 


/*****************************************************************
** Function: getLocation()
** Description: returns player's location
** Parameters: none
*****************************************************************/
Space* Player::getLocation()
{
	return location;
}


/*****************************************************************
** Function: payCashier
** Description: determines if player can pay or not
** Parameters: pointer to space
*****************************************************************/
bool Player::payCashier(Space *ptr)
{
	if (ptr->getRoomName() != "The Gate")
	{
		std::cout << "There is no one to pay here..." << std::endl;
	}
	else
	{
		int total = 0;
		for (int i = 0; i < 6; i++)
		{
			total += itemBag[i].getPrice();
		}
		if (total > wallet)
		{
			std::cout << "**You hand the Gatekeeper your coin-purse...**" << std::endl;
			std::cout << "Gatekeeper: This feels rather light for the goods you want to purchase..." << std::endl;
			return false;
		}
		else
		{
			std::cout << "**You hand the gatekeeper your coin-purse and he extracts the necessary amount for payment**" << std::endl;
			wallet = wallet - total;
			return true;
		}
	}
}


/*****************************************************************
** Function: move()
** Description: lets the player move to a different room
** Parameters: pointer to space
*****************************************************************/
void Player::move(Space *room)
{
	int c;
	room->getExits();
	std::cout << "Where would you like to move?" << std::endl;
	std::cout << "8 - North\n9 - North East\n6 - East\n3 - South East\n2 - South\n1 - South West\n4 - West\n7 - North West\n5 - Exit" << std::endl;
	std::cin >> c;
	switch (c)
	{
	case 8: 
		if (room->getNorth() == NULL)
			std::cout << "Can't move that direction." << std::endl;
		else
			location = room->getNorth();
		break;
	case 9: 
		if (room->getNE() == NULL)
			std::cout << "Can't move that direction." << std::endl;
		else
			location = room->getNE();
		break;
	case 6: 
		if(room->getEast() == NULL)
			std::cout << "Can't move that direction." << std::endl;
		else
			location = room->getEast();
		break;
	case 3: 
		if(room->getSE() == NULL)
			std::cout << "Can't move that direction." << std::endl;
		else
			location = room->getSE();
		break;
	case 2: 
		if(room->getSouth() == NULL)
			std::cout << "Can't move that direction." << std::endl; 
		else
			location = room->getSouth();
		break;
	case 1: 
		if(room->getSW() == NULL)
			std::cout << "Can't move that direction." << std::endl; 
		else
			location = room->getSW();
		break;
	case 4: 
		if(room->getWest() == NULL)
			std::cout << "Can't move that direction." << std::endl; 
		else
			location = room->getWest();
		break;
	case 7: 
		if(room->getNW() == NULL)
			std::cout << "Can't move that direction." << std::endl; 
		else
			location = room->getNW();
		break;
	case 5: break;
	}
}


/*****************************************************************
** Function: setLocation()
** Description: updates the players location
** Parameters: pointer to space
*****************************************************************/
void Player::setLocation(Space *ptr)
{
	location = ptr;
}


/*****************************************************************
** Function: displayList()
** Description: shows player's shopping list
** Parameters: none
*****************************************************************/
void Player::displayList()
{
	std::cout << "Here are the items on your list: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Item " << i + 1 << ": " << shoppingList[i] << std::endl;
	}
}


/*****************************************************************
** Function: displayBag()
** Description: displays player's inventory
** Parameters: none
*****************************************************************/
void Player::displayBag()
{
	std::cout << "Here are the items in your bag: " << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Item #" << i + 1 << "- Name: " << itemBag[i].getName() << std::endl;
		std::cout << "Item Description: " << itemBag[i].getItemDescription() << std::endl;
		std::cout << "Price: $" << itemBag[i].getPrice() << std::endl;
	}
}


/*****************************************************************
** Function: initializeList()
** Description: creates player's shopping list
** Parameters: none
*****************************************************************/
void Player::initializeList()
{
	shoppingList[0] = "A Hungry Man Dinner"; //frozen foods
	shoppingList[1] = "An apple"; //produce
	shoppingList[2] = "Sausages"; //butchers
	shoppingList[3] = "Milk"; // dairy
	shoppingList[4] = "French Bread"; //bakery
}


/*****************************************************************
** Function: initializeBag()
** Description: makes player's bag contain nothing
** Parameters: none
*****************************************************************/
void Player::initializeBag()
{
	for (int i = 0; i < 6; i++)
	{
		itemBag[i].setItemDescription("");
		itemBag[i].setName("");
		itemBag[i].setPrice(0);
	}
}


/*****************************************************************
** Function: checkWallet()
** Description: displays how much money player has
** Parameters: none
*****************************************************************/
void Player::checkWallet()
{
	std::cout << "Coins in purse: " << wallet << std::endl;
}
