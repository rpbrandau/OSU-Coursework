/*****************************************************************
** Program Filename: player.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Header for Player class
*****************************************************************/
//#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "space.hpp"
#include "item.hpp"

class Player
{
private:
	Item itemBag[6];
	std::string shoppingList[5];
	int wallet;
	Space *location;
	int itemCount;

public:
	Player();
	~Player();
	void throwItem();
	void searchRoom(Space *room);
	void addItem(Space *ptr);
	bool payCashier(Space *ptr);
	void move(Space *room);
	void initializeList();
	void displayList();
	void displayBag();
	void checkWallet();
	void initializeBag();
	void setLocation(Space *ptr);
	Space* getLocation();
};
#endif // !PLAYER_HPP
