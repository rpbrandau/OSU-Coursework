/*****************************************************************
** Program Filename: queue.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/28/16
** Description: header file for Queue class
*****************************************************************/
//#pragma once

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "node.hpp"
#include <iostream>

class Queue
{
private:
	Node *front;
	Node *rear;

public:
	Queue();
	~Queue();
	void addBack(int data);
	int getFront();
	void removeFront();
	bool isEmpty();

};
#endif // !QUEUE_HPP
