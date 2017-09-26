/*****************************************************************
** Program Filename: assignment3.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/21/16
** Description: Main method for testing creature classes
*****************************************************************/

//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "creature.hpp"
#include "medusa.hpp"
#include "gollum.hpp"
#include "reptilePeople.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
Creature *createFighter(int choice);

int main()
{
	srand(time(NULL));
	Creature *fighterA;
	Creature *fighterB;
	int choice = 0;

	std::cout << "Please select Fighter A:" << std::endl;
	std::cout << " 1 - Medusa \n 2 - Gollum \n 3 - Reptile Person \n 4 - Blue Men \n 5 - Harry Potter" << std::endl;
	std::cin >> choice;
	fighterA = createFighter(choice);
	std::cout << "Please select Fighter B:" << std::endl;
	std::cout << " 1 - Medusa \n 2 - Gollum \n 3 - Reptile Person \n 4 - Blue Men \n 5 - Harry Potter" << std::endl;
	std::cin >> choice;
	fighterB = createFighter(choice);
	std::cout << std::endl;

	bool faDead = false;
	bool fbDead = false;
	int round = 1;
	int atk = 0;
	int def = 0;
	std::cout << "LETS GET READY TO RUMBLEEEEEE!!!" << std::endl;
	std::cout << std::endl;
	while (faDead == false && fbDead == false)
	{
		std::cout << "Round: " << round << ". FIGHT!!!" << std::endl;
		std::cout << std::endl;
		atk = fighterA->attack();
		def = fighterB->defend(atk);
		std::cout << std::endl;
		std::cout << std::endl;

		atk = fighterB->attack();
		def = fighterA->defend(atk);
		fbDead = fighterB->deathCheck();
		faDead = fighterA->deathCheck();
		std::cout << std::endl;
		std::cout << std::endl;
		round++;
	}
	if (faDead == true && fbDead == true)
	{
		std::cout << "What a fight! " << fighterA->getType() << " and " << fighterB->getType() << " have knocked each other out!!!" << std::endl;
		std::cout << "We will call this one a draw!" << std::endl;
	}
	else if (faDead == true)
	{
		std::cout << fighterB->getType() << " has defeated " << fighterA->getType() << " !" << std::endl;
	}
	else if (fbDead == true)
	{
		std::cout << fighterA->getType() << " has defeated " << fighterB->getType() << " !" << std::endl;
	}
	
    delete fighterA;
    delete fighterB;

    return 0;
}


/*****************************************************************
** Function: creatureFighter(int)
** Description: Returns a pointer to a derived class creature
** Parameters: int
*****************************************************************/
Creature *createFighter(int choice)
{
	if (choice == 1) //medusa
	{
		std::cout << "Medusa selected" << std::endl;
		Medusa *medusaPtr = new Medusa();
		return medusaPtr;

	}
	else if (choice == 2) //gollum
	{
		std::cout << "Gollum selected" << std::endl;
		Gollum *gollumPtr = new Gollum();
		return gollumPtr;
	}
	else if (choice == 3) //reptilePeople
	{
		std::cout << "Reptile Person selected" << std::endl;
		ReptilePeople *reptilePtr = new ReptilePeople();
		return reptilePtr;
	}
	else if (choice == 4) //blueMen
	{
		std::cout << "Blue Men selected" << std::endl;
		BlueMen *bluePtr = new BlueMen();
		return bluePtr;
	}
	else if (choice == 5) //harryPotter
	{
		std::cout << "Harry Potter selected" << std::endl;
		HarryPotter *harryPtr = new HarryPotter();
		return harryPtr;
	}
	else
	{
		std::cout << "Uh oh... you didn't select an option correctly." << std::endl;
		std::cout << "A random fighter will be chosen for you." << std::endl;
		int c = rand() % 5 + 1;
		createFighter(c);
	}
}
