/*****************************************************************
** Program Filename: finalAssignment.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/6/16
** Description: Main method for final assignment program
*****************************************************************/

//#include "stdafx.h"

#include "bakery.hpp"
#include "butchers.hpp"
#include "cannedGoods.hpp"
#include "dairy.hpp"
#include "entrance.hpp"
#include "frozenFoods.hpp"
#include "home.hpp"
#include "item.hpp"
#include "outside.hpp"
#include "player.hpp"
#include "produce.hpp"
#include "space.hpp"


//prototypes
void preface();
Space* homeSetup(Space *p1, Space *p2);
Space* outSetup(Space *p1, Space *p2, Space *p3);
Space* entSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5, Space *p6, Space *p7);
Space* butchSetup(Space *p1, Space *p2, Space *p3, Space *p4);
Space* bakerSetup(Space *p1, Space *p2, Space *p3, Space *p4);
Space* prodSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5);
Space* canSetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5, Space *p6, Space *p7);
Space* dairySetup(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5);
Space* frozenSetup(Space *p1, Space *p2, Space *p3, Space *p4);
Space* unhook(Space *p1);


int main()
{
	bool gameFinished = false;
	int c = 0;
	bool pay = false;
	bool entrance = false;

	//Creating rooms & initializing pointers
	Space *homePtr = new Home; //room 1
	Space *outPtr = new Outside; //room 2
	Space *entPtr = new Entrance; //room 3
	Space *butchPtr = new Butchers; //room 4
	Space *bakeryPtr = new Bakery; //room 5
	Space *prodPtr = new Produce; //room 6
	Space *canPtr = new CannedGoods; //room 7
	Space *dairyPtr = new Dairy; //room 8
	Space *frozenPtr = new FrozenFoods; //room 9

	//linking rooms
	homePtr = homeSetup(homePtr, outPtr);
	outPtr = outSetup(outPtr, homePtr, entPtr);
	entPtr = entSetup(entPtr, outPtr, butchPtr, bakeryPtr, prodPtr, canPtr, dairyPtr);
	butchPtr = butchSetup(butchPtr, prodPtr, canPtr, entPtr);
	bakeryPtr = bakerSetup(bakeryPtr, entPtr, dairyPtr, canPtr);
	prodPtr = prodSetup(prodPtr, butchPtr, frozenPtr, canPtr, entPtr);
	canPtr = canSetup(canPtr, frozenPtr, prodPtr, dairyPtr, bakeryPtr, entPtr, butchPtr);
	dairyPtr = dairySetup(dairyPtr, frozenPtr, bakeryPtr, entPtr, canPtr);
	frozenPtr = frozenSetup(frozenPtr, prodPtr, canPtr, dairyPtr);

	//story function
	preface();

	//player creation
	Player knight;
	//setting player to home
	knight.setLocation(homePtr);

	//game loop
	while (!gameFinished)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 - Search Room\n2 - Move\n3 - Pickup Item\n4 - Check List\n5 - Check Bag\n6 - Check Wallet\n7 - Pay Guard\n8 - Throw Item\n9 - Special" << std::endl;
		std::cin >> c;
		switch (c)
		{
		case 1:
			knight.searchRoom(knight.getLocation());
			break;
		case 2:
		{
			knight.move(knight.getLocation());
			if (knight.getLocation()->getRoomName() == "The Gate" && entrance == false)
			{
				entrance = true;
				entPtr = unhook(entPtr); //unlinking entrance from outside
				outPtr = unhook(outPtr); //unlinking outside from home & entrance
				homePtr = unhook(homePtr); //unlinking home from outside
				std::cout << "The gate closes behind you..." << std::endl;
				delete outPtr; //deleting room
			}
			if (knight.getLocation()->getRoomName() == "Home" && pay == true)
			{
				std::cout << "You have arrived home after a long day of questing." << std::endl;
				std::cout << "Mom: Thanks for making a trip to the store, sweetie!" << std::endl;
				std::cout << "Mom: I mean, questing in far-away lands!" << std::endl;
				gameFinished = true;
			}
		}
			break;
		case 3:
			knight.addItem(knight.getLocation());
			break;
		case 4:
			knight.displayList();
			break;
		case 5:
			knight.displayBag();
			break;
		case 6:
			knight.checkWallet();
			break;
		case 7:
			pay = knight.payCashier(knight.getLocation());
			{
				if (pay == false) //can not pay
				{
					std::cout << "You don't have enough coins to pay for your items." << std::endl;
					std::cout << "(Try throwing some away)" << std::endl;
				}
				else //pay successful
				{
					Space *outPtr = new Outside; //creating a new room in runtime
					homePtr = homeSetup(homePtr, outPtr); //linking home to new room
					outPtr = outSetup(outPtr, homePtr, entPtr); //linking new room to home & entrance room
					entPtr = entSetup(entPtr, outPtr, butchPtr, bakeryPtr, prodPtr, canPtr, dairyPtr); //linking entrance to new room
					entrance = false;
				}
			}
			break;
		case 8:
			knight.throwItem();
			break;
		case 9:
			knight.getLocation()->special();
			break;
		}

	}


	//deleting pointers
	delete homePtr;
	delete outPtr;
	delete entPtr;
	delete butchPtr;
	delete bakeryPtr;
	delete prodPtr;
	delete canPtr;
	delete dairyPtr;
	delete frozenPtr;
    return 0;
}

/*****************************************************************
** Function: preface()
** Description: Game's story setup.
** Parameters: none
*****************************************************************/
void preface()
{
	//start of story here
	std::cout << "You wake up after what seems to be a long slumber. You glance at the clock on your nightstand," << std::endl;
	std::cout << "but it is flashing 12:00. You rub the sleep from your eyes, roll out of bed, and put on some clothes." << std::endl;
	std::cout << "As you walk into the livng room, you notice a note on the table." << std::endl;
	std::cout << "It reads: " << std::endl;
	std::cout << std::endl;
	std::cout << "To my darling knight:" << std::endl;
	std::cout << "I am putting you in charge of carrying out an important quest." << std::endl;
	std::cout << "I need you to brave the Wastes and journey to far-away lands to aquire some special ingredients for supper." << std::endl;
	std::cout << "I have left you with the list and enough gold coins to purchase what we need" << std::endl;
	std::cout << "(as well as a few extra coins, should you desire a treat)." << std::endl;
	std::cout << "May your journey be without troubles!" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	//std::cout << "Love, \nMom \n \n \nPS. Watch out for that lumbering beast in the Wastes!" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}


/*****************************************************************
** Function: (room)Setup()
** Description: These functions handle the linking of the rooms
** Parameters: Pointers to Space (2-7 depending on room)
*****************************************************************/
Space* homeSetup(Space *home, Space *outside)
{
	home->ptrSetup(outside);
	return home;
}
Space* outSetup(Space *outside, Space *home, Space *entrance)
{
	outside->ptrSetup(home, entrance);
	return outside;
}
Space* entSetup(Space *entrance, Space *outside, Space *butchers, Space *bakery, Space *produce, Space *canned, Space *dairy)
{
	entrance->ptrSetup(outside, butchers, bakery, produce, canned, dairy);
	return entrance;
}
Space* butchSetup(Space *butchers, Space *produce, Space *canned, Space *entrance)
{
	butchers->ptrSetup(produce, canned, entrance);
	return butchers;
}
Space* bakerSetup(Space *bakery, Space *entrance, Space *dairy, Space *canned)
{
	bakery->ptrSetup(entrance, dairy, canned);
	return bakery;
}
Space* prodSetup(Space *produce, Space *butchers, Space *frozen, Space *canned, Space *entrance)
{
	produce->ptrSetup(butchers, frozen, canned, entrance);
	return produce;
}
Space* canSetup(Space *canned, Space *frozen, Space *produce, Space *dairy, Space *bakery, Space *entrance, Space *butchers)
{
	canned->ptrSetup(frozen, produce, dairy, bakery, entrance, butchers);
	return canned;
}
Space* dairySetup(Space *dairy, Space *frozen, Space *bakery, Space *entrance, Space *canned)
{
	dairy->ptrSetup(frozen, bakery, entrance, canned);
	return dairy;
}
Space* frozenSetup(Space *frozen, Space *produce, Space *canned, Space *dairy)
{
	frozen->ptrSetup(produce, canned, dairy);
	return frozen;
}


/*****************************************************************
** Function: unhook()
** Description: calls a room's unhook function - destroys links to rooms
** Parameters: Pointer to space
*****************************************************************/
Space* unhook(Space *ptr)
{
	ptr->unhook();
	return ptr;
}

