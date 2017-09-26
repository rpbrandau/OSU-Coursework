/*****************************************************************
** Program Filename: stack.cpp
** Author: **Provided by anonymous student**
** Date: 8/8/16
** Description: Source for Stack class functions
** Note: Riley Brandau did not alter any of this code aside from inserting this header text.
*****************************************************************/
//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "stack.hpp"

using std::cout;


/*********************************************************************
** Function: Stack
** Description: Constructor sets top pointer to NULL
** Parameters: N/A
*********************************************************************/
Stack::Stack()
{
	top = NULL;
}

/*********************************************************************
** Function: push
** Description: pushes the argument onto the stack
** Parameters: int input
*********************************************************************/
void Stack::push(int input)
{
	top = new StackNode(input, top);
}

/*********************************************************************
** Function: peek
** Description: returns the value on top of the stack
*********************************************************************/
int Stack::peek()
{

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		return top->value;
	}

	//Code for Exception
	/*if (isEmpty()) throw Stack::Underflow();
	return top->value;*/
}

/*********************************************************************
** Function: pop
** Description: removes the value at the top of the stack
** Parameters: int input
*********************************************************************/
void Stack::pop()
{
	StackNode* temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		temp = top;
		top = top->next;
		delete temp;
	}

	//Code for Exception
	/*if (isEmpty()) throw Stack::Underflow();
	temp = top;
	top = top->next;
	delete temp;*/

}

/*********************************************************************
** Function: isEmpty
** Description: returns true if the stack is empty or false if stack
is not empty
*********************************************************************/
bool Stack::isEmpty() const
{
	if (!top)
		return true;
	else
		return false;
}
