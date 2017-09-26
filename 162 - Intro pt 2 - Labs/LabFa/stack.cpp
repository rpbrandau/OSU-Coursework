/*****************************************************************
** Program Filename: stack.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/28/16
** Description: source file for Stack class
*****************************************************************/
//#include "stdafx.h"
#include "stack.hpp"


/*****************************************************************
** Function: stack()
** Description: constructor
** Parameters: none
*****************************************************************/
Stack::Stack()
{
	head = NULL;
	//tail = NULL;
}


/*****************************************************************
** Function: ~stack()
** Description: destructor
** Parameters: none
*****************************************************************/
Stack::~Stack()
{
	Node* garbage;
	while (head != NULL)
	{
		garbage = head; //assign pointer to head
		head = head->next; //assign head to next node
		delete garbage; //delete pointer
	}
}


/*****************************************************************
** Function: push()
** Description: creates a new node with passed data; is assigned to head ptr
** Parameters: integer
** Source: modified from course textbook
*****************************************************************/
void Stack::push(int val)
{
	head = new Node(val, head);
}


/*****************************************************************
** Function: pop()
** Description: removes the top node and reads the value
** Parameters: none
*****************************************************************/
void Stack::pop()
{
	if (isEmpty())
	{
		std::cout << "Nothing left to pop! (stack is empty)" << std::endl;
	}
	else
	{
		Node* nodePtr; //create a node pointer
		nodePtr = head; //assign pointer to head
		head = head->next; //assign head pointer to next node in line (since current "head" node will be deleted in the pop())
		std::cout << "Popping " << nodePtr->data << " from the stack." << std::endl;
		delete nodePtr; //delete pointer
	}
}


/*****************************************************************
** Function: peek()
** Description: displays top node value
** Parameters: none
*****************************************************************/
int Stack::peek()
{
	if (head == NULL)
	{
		std::cout << "The stack is empty." << std::endl;
		return NULL;
	}
	else if (head != NULL)
	{
		//std::cout << "Taking a peek at the top of the stack: " << head->data << std::endl;
		return head->data;
	}
}


/*****************************************************************
** Function: isEmpty()
** Description: returns true if stack is empty
** Parameters: none
*****************************************************************/
bool Stack::isEmpty()
{
	if (head == NULL) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
