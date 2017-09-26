/*****************************************************************
** Program Filename: list.cpp
** Author: Riley Brandau
** Date: 6/22/16
** Description: Source file for List class definitions
*****************************************************************/
//#include "stdafx.h"
#include "list.hpp"
#include <iostream>
#include <iomanip>


/*****************************************************************
** Function: List()
** Description: constructor
*****************************************************************/
List::List()
{
	dyn_Cart = new Item[4];
}



/*****************************************************************
** Function: printCart()
** Description: displays the contents of the cart
*****************************************************************/
void List::printCart()
{
	for (int i = 0; i < cartSize; i++)
	{
		std::cout << "Item #" << i + 1 << std::endl;
		std::cout << "Item name: " << dyn_Cart[i].getName() << std::endl;
		std::cout << "Item type: " << dyn_Cart[i].getUnit() << std::endl;
		std::cout << "Unit Price: $" << std::setprecision(4) << dyn_Cart[i].getUnitPrice() << std::endl;
		std::cout << "Amount to buy: " << dyn_Cart[i].getNumToBuy() << std::endl;
		std::cout << "Item total: $" << std::setprecision(4) << dyn_Cart[i].getSubTotal() << std::endl;
		std::cout << std::endl;
	}
	setTotal();
	std::cout << "Total cost of cart: $" << std::setprecision(4) << total << std::endl;
}



/*****************************************************************
** Function: setTotal()
** Description: calculates the total of the cart
*****************************************************************/
void List::setTotal()
{
	total = 0.0;

	for (int i = 0; i < cartSize; i++)
	{
		total += dyn_Cart[i].getSubTotal();
	}
}



/*****************************************************************
** Function: getTotal()
** Description: get method
*****************************************************************/
double List::getTotal()
{
	return total;
}



/*****************************************************************
** Function: addItem()
** Description: add's an item to the cart
*****************************************************************/
void List::addItem(Item a, int b)
{
	dyn_Cart[b] = a;
}




/*****************************************************************
** Function: delItem()
** Description: deletes and item from the cart (sets everything to zero)
*****************************************************************/
void List::delItem(int x, int s)
{
	for (int i = 0; i < s; i++)
	{
		if (x == i + 1)
		{
			Item x;
			x.setItemName("DELETED");
			x.setNumToBuy(0);
			x.setUnit(10);
			x.setUnitPrice(0.0);
			dyn_Cart[i] = x;
		}
	}
}



/*****************************************************************
** Function: dblList()
** Description: copies old cart into a new cart double the size of old cart
*****************************************************************/
void List::dblList(int s) 
{
	Item *temp = dyn_Cart;
	dyn_Cart = new Item[s];
	
	for (int i = 0; i < cartSize; i++)
	{
		dyn_Cart[i] = temp[i];
	}

	delete[] temp;
	cartSize = 2 * cartSize;
}
