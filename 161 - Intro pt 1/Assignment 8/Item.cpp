/*****************************************************************
 * Author: Riley Brandau
 * Date: 2/23/16
 * Description: This is the cpp file for a class called Item.
 * It contains the definitions for the functions defined in the
 * Item header file.
****************************************************************/

#include "Item.hpp"
#include <string>
#include <iostream>
using namespace std;

/**************************************************************
 * *********************SET METHODS****************************
**************************************************************/

void Item::setName(string n)
{
	name = n;
}

void Item::setPrice(double p)
{
	price = p;
}

void Item::setQuantity(int q)
{
	quantity = q;
}


/************************************************************
 * ********************GET METHODS***************************
************************************************************/

string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

int Item::getQuantity()
{
	return quantity;
}


/*************************************************************
 * ********************CONSTRUCTORS***************************
*************************************************************/

Item::Item() //default
{
	setName("");
	setPrice(0.0);
	setQuantity(0);
}

Item::Item(string n, double p, int q)
{
	setName(n);
	setPrice(p);
	setQuantity(q);
}
