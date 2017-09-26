/*****************************************************************
** Program Filename: list.hpp
** Author: Riley Brandau
** Date: 6/22/16
** Description: Header file for list class
*****************************************************************/
//#pragma once
#include "item.hpp"
#ifndef LIST_HPP
#define LIST_HPP

class List
{
private:
	//Item stat_Cart[4];  //static cart for testing
	Item *dyn_Cart;   //dynamic cart
	double total = 0.0;
	int cartSize = 4;
public:
	List();
	void printCart();
	void setTotal();
	double getTotal();
	void addItem(Item a, int b);
	void delItem(int num, int size);
	void dblList(int s);
};

#endif

