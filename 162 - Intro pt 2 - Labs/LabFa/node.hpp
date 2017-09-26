/*****************************************************************
** Program Filename: node.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/28/16
** Description: defines Node structure
*****************************************************************/
//#pragma once

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

struct Node
{
	int data;
	Node* next;
	//Node* prev;
	Node(int val, Node* ptr = NULL)
	{
		data = val;
		next = ptr;
	}
};
#endif // !NODE_HPP
