/********************************************************************************
 * Author: Riley Brandau
 * Date: 2/23/16
 * Description: This is a header file for a class called Item.
 * Each item object created will have a String field for its name,
 * a double field for it's price, and an int field for its quantity.
*******************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iostream>
using namespace std;

class Item
{
	private:
		//MEMBER VARIABLES
		string name;
		double price;
		int quantity;
	public:
		//GET METHODS
		string getName();
		double getPrice();
		int getQuantity();

		//SET METHODS
		void setName(string);
		void setPrice(double);
		void setQuantity(int);

		//CONSTRUCTORS
		Item(); //default
		Item(string, double, int);
};
#endif
