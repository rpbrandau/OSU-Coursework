/*****************************************************************
** Program Filename: list.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/19/16
** Description: Source file for List class
*****************************************************************/
//#include "stdafx.h"
#include "list.hpp"

/*****************************************************************
** Function: List()
** Description: constructor
** Parameters: none
*****************************************************************/
List::List()
{
	head = NULL;
}


/*****************************************************************
** Function: insert()
** Description: creates a new node and adds a char to store
** Parameters: char variable
*****************************************************************/
void List::insert(char x)
{
	if (head == NULL) //if the list is empty
	{
		head = new node(x);
		temp = head;
		tail = head;
	}
	else //if the list is not empty
	{
		temp = head;
		while (temp->next != NULL) //traverse the list until the end is reached
		{
			temp = temp->next;
		}
		temp->next = new node(x); //add a node at the end
		tail = head;              //set tail to the head of the list
	}
}


/*****************************************************************
** Function: remove()
** Description: displays node contents then deletes it
** Parameters: none
*****************************************************************/
char List::remove()
{
	temp = head;
	if (!head)
	{
		char a = ' ';
		return a;
	}
	while (temp)
	{
		char a;
		a = temp->data;
		head = head->next;
		delete temp;
		return a;
	}
}


/*****************************************************************
** Function: displayHead()
** Description: displays what the first node contains
** Parameters: none
*****************************************************************/
void List::displayHead()
{
	temp = head;
	std::cout << temp->data << std::endl;
}
