/********************************************************************************
 * Author: Riley Brandau
 * Date: 2/23/16
 * Description: This file contains the definitions for the ShoppingCart class
*******************************************************************************/
#include "Item.hpp"
#include "ShoppingCart.hpp"
#include <string>
#include <iostream>
using namespace std;

/******************************************************************************
 * ***********************DEFAULT CONSTRUCTOR**********************************
******************************************************************************/

ShoppingCart::ShoppingCart()                  //default constructor that loops
					      //through each element (pointer)
					      //of the array and sets each
					      //element (pointer) to NULL
{	
	for(int count = 0; count < 100; count++)
	{
		cartArray[count] = NULL; //might not be able to access cartArray?
	}
	
	arrayEnd = 0;			      //Initializing arrayEnd to 0
}



/****************************************************************************
 * *********************ADD ITEM FUNCTION************************************
****************************************************************************/

void ShoppingCart::addItem(Item *a)
{
	cartArray[arrayEnd] = a; //adds the item to the pointer array

	arrayEnd++;               //updates arrayEnd for next item
}


/**************************************************************************
 * ******************TOTAL PRICE FUNCTION**********************************
This function will loop through the array of pointers and extract the
price and quantity for each element, multiply them together, and add
it to a running total.****************************************************
**************************************************************************/

double ShoppingCart::totalPrice()
{
	double total = 0.0;

	for(int count = 0; count < arrayEnd; count++)
	{
		double p;
		int q;
		Item a = *cartArray[count];
		p = a.getPrice(); 
		q = a.getQuantity();
		total += p*q;
	}
	return total;
}
