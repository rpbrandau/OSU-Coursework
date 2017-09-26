/*****************************************************************
** Program Filename: assignment1.cpp
** Author: Riley Brandau
** Date: 6/22/16
** Description: Main method for testing item and list classes
*****************************************************************/

//#include "stdafx.h"
#include "list.hpp"
#include <iostream>

int intVal(); //validation
double dblVal(); //validation
Item addCart();

int main()
{
	int arraySize = 4;
	int arrayRoom = 4;
	int cartPos = 0;
	int choiceA = 0;
	int choiceB = 0;
	List cart;

	do {
		std::cout << "Would you like to add an item to your cart?" << std::endl;
		std::cout << "Enter 1 for Yes, 2 for No, 3 to Exit." << std::endl;
		choiceA = intVal();
		if (choiceA == 1)
		{
			if (arrayRoom > 0) //still room in the array for an item
			{
				Item x = addCart();
				cart.addItem(x, cartPos);
				arrayRoom--;
				cartPos++;
			}
			else  //no more room in the array for an item
			{
				arraySize = 2 * arraySize;
				arrayRoom = arraySize / 2;
				cart.dblList(arraySize); //create new array & copy old array into it
				Item x = addCart();
				cart.addItem(x, cartPos);
				arrayRoom--;
				cartPos++;
			}
		}
		else if (choiceA == 2)
		{
			cart.printCart();
			std::cout << "Do you want to delete an item?" << std::endl;
			std::cout << "1 for yes, 2 for no" << std::endl;
			choiceB = intVal();
			if (choiceB == 1)
			{
				if (arrayRoom < arraySize)
				{
					int c = 0;
					std::cout << "Which item would you like to remove?" << std::endl;
					std::cout << "Enter an integer." << std::endl;
					c = intVal();
					std::cout << "Item number " << c << " deleted." << std::endl;
					cart.delItem(c, arraySize);
					arrayRoom++;
				}
				else
				{
					std::cout << "Nothing to remove!" << std::endl;
				}
			}
			else if (choiceB == 2)
			{
				cart.printCart();
			}
		}
		else
		{
			cart.printCart();
			std::cout << std::endl;
			std::cout << "Exiting Program." << std::endl;
		}
	} while (choiceA != 3);

    return 0;
}



/*****************************************************************
** Function: intVal()
** Description: integer validation function
*****************************************************************/
int intVal()
{
	int val;
	while (!(std::cin >> val))
	{
		std::cout << "You did not enter an integer." << std::endl;
		std::cin.clear();
		std::cin.ignore(20, '\n');
	}
	return val;
}


/*****************************************************************
** Function: dblVal()
** Description: double (number) validation function
*****************************************************************/
double dblVal()
{
	double val;
	while (!(std::cin >> val))
	{
		std::cout << "You did not enter a double." << std::endl;
		std::cin.clear();
		std::cin.ignore(20, '\n');
	}
	return val;
}


/*****************************************************************
** Function: addCart()
** Description: adds an item to the cart
*****************************************************************/
Item addCart()
{
	Item x;
	std::string n;
	int a;
	double b;
	std::cout << "Enter item name: " << std::endl;
	std::cin >> n;
	x.setItemName(n);
	std::cout << "Enter item type: " << std::endl;
	std::cout << "(1 = Box, 2 = Ounce, 3 = Pound, 4 = Package)" << std::endl;
	a = intVal();
	x.setUnit(a);
	std::cout << "Enter number to buy: " << std::endl;
	a = intVal();
	x.setNumToBuy(a);
	std::cout << "Enter price per item: " << std::endl;
	b = dblVal();
	x.setUnitPrice(b);
	return x;
}
