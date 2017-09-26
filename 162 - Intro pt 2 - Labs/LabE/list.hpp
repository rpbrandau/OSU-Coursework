/*****************************************************************
** Program Filename: list.h
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/19/16
** Description: Header file for List class
*****************************************************************/
//#pragma once

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List
{
private:
	struct node  //adapted from book code to use char variable
	{
		char data;
		node* next;
		node(char data1, node *next1 = NULL)
		{
			data = data1;
			next = next1;
		}
	};

	node* head; 
	node* temp;
	node* tail;


public:
	List();
	//~List();
	void insert(char x);
	void displayHead();
	char remove();

};


#endif
