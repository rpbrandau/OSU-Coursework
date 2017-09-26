/*****************************************************************
** Program Filename: queue.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/28/16
** Description: source file for Queue class
*****************************************************************/
//#include "stdafx.h"
#include "queue.hpp"

/*****************************************************************
** Function: queue()
** Description: constructor
** Parameters: none
*****************************************************************/
Queue::Queue()
{
	front = NULL;
	rear = NULL;
}


/*****************************************************************
** Function: ~queue()
** Description: destructor
** Parameters: none
*****************************************************************/
Queue::~Queue()
{
	Node* garbage;
	while (front != NULL)
	{
		garbage = front; //assign pointer to head
		front = front->next; //assign head to next node
		delete garbage; //delete pointer
	}
}


/*****************************************************************
** Function: addBack()
** Description: adds a node w/ data to end of queue
** Parameters: integer
*****************************************************************/
void Queue::addBack(int data)
{
	Node* newNode = new Node(data);
	if (front == NULL && rear == NULL)
	{
		front = rear = newNode;
	}
	else
	{
		rear->next = newNode; //linking last node to new node
		rear = newNode; //setting rear to last node
	}
	//delete newNode;
}


/*****************************************************************
** Function: getFront()
** Description: displays top node value
** Parameters: none
*****************************************************************/
int Queue::getFront()
{
	if (isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		return NULL;
	}
	else //if (front != NULL)
	{
		//std::cout << "Taking a peek at the front of the queue: " << front->data << std::endl;
		return front->data;
	}
}


/*****************************************************************
** Function: removeFront()
** Description: deletes front node and reads out value
** Parameters: none
*****************************************************************/
void Queue::removeFront()
{
	Node* newNode = front;
	if (isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
	}
	else if (front == rear)
	{
		std::cout << "The first item (" << newNode->data << ") in the queue has been removed." << std::endl;
		front = rear = NULL;
	}
	else 
	{
		front = front->next;
		std::cout << "The first item (" << newNode->data << ") in the queue has been removed." << std::endl;
		//delete newNode;
	}
}


/*****************************************************************
** Function: isEmpty()
** Description: returns true if queue is empty
** Parameters: none
*****************************************************************/
bool Queue::isEmpty()
{
	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
