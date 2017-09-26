/*****************************************************************
** Program Filename:labB.cpp
** Author: Riley Brandau
** Date: 6/29/16
** Description: main method for testing dice/loadedDice classes
*****************************************************************/
//#include "stdafx.h"
#include "dice.hpp"
#include "loadedDice.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL)); //initializing random seed
	int d = 0;
	int ld = 0;
	std::cout << "Please enter how many sides you'd like your normal dice to have: " << std::endl;
	std::cin >> d;
	std::cout << "Please enter how many sides you'd like your loaded dice to have: " << std::endl;
	std::cin >> ld;
	Dice a1(d);
	Dice a2(d);
	LoadedDice b1(ld);
	LoadedDice b2(ld);
	int a1Roll = 0;
	int a2Roll = 0;
	int b1Roll = 0;
	int b2Roll = 0;
	int rSum = 0;
	int lSum = 0;

	std::ofstream output;
	output.open("diceStats.txt");

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Roll #" << i + 1 << std::endl;
		a1Roll = a1.roll();
		std::cout << "Dice A roll: " << a1Roll << std::endl;
		a2Roll = a2.roll();
		std::cout << "Dice B roll: " << a2Roll << std::endl;
		rSum = a1Roll + a2Roll;
		std::cout << std::endl;
		
		b1Roll = b1.roll();
		std::cout << "Dice A (Loaded) roll: " << b1Roll << std::endl;
		b2Roll = b2.roll();
		std::cout << "Dice B (Loaded) roll: " << b2Roll << std::endl;
		lSum = b1Roll + b2Roll;
		std::cout << std::endl;

		std::cout << "Regular Dice Sum: " << rSum << std::endl;
		std::cout << "Loaded Dice Sum: " << lSum << std::endl;
		std::cout << std::endl;

		output << "Roll #" << i + 1 << std::endl;
		output << "Dice A Roll: " << a1Roll << std::endl;
		output << "Dice B Roll: " << a2Roll << std::endl;
		output << "Dice A (loaded) Roll: " << b1Roll << std::endl;
		output << "Dice B (loaded) Roll: " << b2Roll << std::endl;
		output << "Normal Dice Sum: " << rSum << std::endl;
		output << "Loaded Dice Sum: " << lSum << std::endl;
	}
	
	output.close();	

    return 0;
}

