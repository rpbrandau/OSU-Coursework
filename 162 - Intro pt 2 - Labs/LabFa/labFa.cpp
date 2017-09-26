/*****************************************************************
** Program Filename: labFa.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/28/16
** Description: driver for stack and queue classes
*****************************************************************/

//#include "stdafx.h"
#include "stack.hpp"
#include "queue.hpp"
#include <stdlib.h>

void menu();
int choice();

int main()
{
	Stack s;
	Queue q;
	int count = 0;
	int num = 0;
	int tNum = 0;
	int menuChoice = 0;
	bool fin = false;

	std::cout << "This program will insert integers into a stack and a queue." << std::endl;
	while (fin != true)
	{
		menu();
		menuChoice = choice();
		switch (menuChoice)
		{
		case 1:
			std::cout << "How many integers would you like to insert?" << std::endl;
			std::cin >> count;
			for (int i = 0; i < count; i++)
			{
				std::cout << "Please enter number " << i + 1 << " of " << count << std::endl;
				std::cin >> num;
				s.push(num);
				q.addBack(num);
				std::cin.ignore();
				std::cin.clear();
				std::cout << std::endl;
			}
			break;
		case 2:
			tNum = s.peek();
			std::cout << "First value of Stack: " << tNum << std::endl;
			tNum = q.getFront();
			std::cout << "First value of Queue: " << tNum << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			s.pop();
			q.removeFront();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "Program driven test initiated..." << std::endl;
			std::cout << "Entering numbers into Stack and Queue..." << std::endl;
			for (int i = 0; i < 5; i++)
			{
				int x = 0;
				x = rand() % 100;
				s.push(x);
				q.addBack(x);
			}
			std::cout << "Removing numbers from Stack and Queue..." << std::endl;
			for (int i = 0; i < 5; i++)
			{
				s.pop();
				q.removeFront();
			}
			std::cout << "Stack and Queue should now be empty." << std::endl;
			std::cout << "Trying to print values not entered (N+1)" << std::endl;
			s.pop();
			q.removeFront();
			
			break;
		case 5:
			std::cout << "Ending program..." << std::endl;
			fin = true;
			break;
		default:
			std::cout << "Enter a valid choice." << std::endl;
			std::cout << std::endl;
			break;
		}
	}
	


    return 0;
}


/*****************************************************************
** Function: menu()
** Description: displays a menu for user
** Parameters: none
*****************************************************************/
void menu()
{
	std::cout << "1: Enter integers" << std::endl;
	std::cout << "2: Look at first value of structures" << std::endl;
	std::cout << "3: Remove first value of structures" << std::endl;
	std::cout << "4: Automated test" << std::endl;
	std::cout << "5: Exit program" << std::endl;
	std::cout << std::endl;
}


/*****************************************************************
** Function: choice()
** Description: captures user's choice
** Parameters: none
*****************************************************************/
int choice()
{
	int c;
	std::cout << "Choice: ";
	std::cin >> c;
	return c;
}

