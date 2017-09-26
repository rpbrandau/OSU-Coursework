/*****************************************************************
** Program Filename: labE.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/19/16
** Description: Main method for testing list class
*****************************************************************/

//#include "stdafx.h"
#include "list.hpp"

int main()
{
	List a;
	char x;
	int num;
	int count;
	std::cout << "How many characters would you like to enter?" << std::endl;
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		std::cout << "Please enter a character to be placed in a list...(" << i+1 << " of "<< count << ")" << std::endl;
		std::cin >> x;
		a.insert(x);
	}
	
	std::cout << "Enter 1 to display head value. Enter 2 to traverse list and end program." << std::endl;
	while(std::cin >> num)
	{
		if (num == 1)
		{
			a.displayHead();
			std::cout << std::endl;
			std::cin.clear();
			std::cout << "Enter 1 to display head value. Enter 2 to traverse list and end program." << std::endl;
		}
	
		if (num == 2)
		{
			char b;
			for(int i = 0; i < count; i++)
			{
				b = a.remove();
				std::cout << b << std::endl;
				std::cin.clear();
			}
			std::cout << std::endl;
			return 0; 
		}
	}
	

    return 0;
}

