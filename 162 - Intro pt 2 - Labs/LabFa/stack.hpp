/*****************************************************************
** Program Filename: stack.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/28/16
** Description: header file for Stack class
*****************************************************************/
//#pragma once

#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"
#include <iostream>


class Stack
{
private:
	Node *head;
	//Node *tail;

public:
	Stack();
	~Stack();
	void push(int d);
	void pop();
	int peek();
	bool isEmpty();

};
#endif // !STACK_HPP
