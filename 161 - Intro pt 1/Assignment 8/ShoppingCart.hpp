/***********************************************************************
 * Author: Riley Brandau
 * Date: 2/23/16
 * Description: This is a header file for a class called Shopping Cart.
 * It creates an array of pointers that point to Item objects and has
 * methods for adding items to the array and returning the total cost
 * of all items in the cart.
************************************************************************/

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP
#include "Item.hpp"
#include <string>
#include <iostream>
using namespace std;

class ShoppingCart
{
	private:
		Item* cartArray[100]; //array of 100 pointer-to-item pointers

		int arrayEnd;		  //keeps track of the index of next empty
					  //spot in the array
	public:
		ShoppingCart();           //default constructor

		void addItem(Item*);      //method that takes a pointer to an item
				          //and adds it to the array
				          
		double totalPrice();      //method for returning cost of ShoppingCart
};
#endif
