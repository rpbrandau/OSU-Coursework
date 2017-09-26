/*****************************************************************
** Program Filename: labFb.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/8/16
** Description: Tests stack code provided by other student.
** Description: Uses provided code to perform postfix calculations.
*****************************************************************/

//#include "stdafx.h"
#include "stack.hpp"
#include <iostream>
#include "postfixCalc.hpp"
void stackTest();

int main()
{
	//testing stack code that was provided
	stackTest();

	Stack calc;
	bool op = false;
	int opRand1, opRand2, x = 0;
	char entry = ' ';




	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "POSTFIX CALCULATOR" << std::endl;
	std::cout << "Please enter an equation in postfix notation (eg. 2 3 + 7 -)" << std::endl;
	std::cout << "Enter an '=' upon completion." << std::endl;
	while (entry != '=')
	{
		std::cin >> entry;
		op = isOp(entry);  //storing isOp bool value in op
		if (!op) //if it's not an operator
		{
			if (entry >= '0' && entry <= '9')
			{
				x = entry - 48; //converting char to int
				calc.push(x);
				//std::cout << x << " pushed to stack." << std::endl;
			}
			else if (entry == ' ') //do nothing if blank space
			{
				break;
			}
		}
		else //perform the operations on the stack of values
		{
			opRand1 = calc.peek(); //store peek in opRand1
			calc.pop();			   //pop stack
			opRand2 = calc.peek(); //store peek in opRand2
			calc.pop();            //pop stack
			calc.push(doOp(opRand1, opRand2, entry)); //call doOp & push result to stack
		}

	}
	
	std::cout << "The result is: " << calc.peek() << std::endl;
	
    return 0;
}

void stackTest()
{
	Stack list;
	bool empty = false;
	std::string result;

	std::cout << "Testing the stack." << std::endl;
	std::cout << "Stack should be empty (should return true): ";
	empty = list.isEmpty();
	if (empty == true)
	{
		result = "true";
	}
	else
	{
		result = "false";
	}
	std::cout << result << std::endl;

	std::cout << "Pushing 5 numbers to stack: 5, 10, 15, 20, 25" << std::endl;
	for (int i = 1; i < 6; i++)
	{
		list.push(i * 5);
	}
	std::cout << "Testing for isEmpty (should return false): ";
	empty = list.isEmpty();
	if (empty == true)
	{
		result = "true";
	}
	else
	{
		result = "false";
	}
	std::cout << result << std::endl;

	std::cout << "Popping values & displaying them: ";
	for (int i = 5; i > 0; i--)
	{
		std::cout << "Top value #" << i << ": " << list.peek() << "(should be " << i * 5 << ")" << std::endl;
		list.pop();
	}

	std::cout << "Stack should be empty (should return true): ";
	empty = list.isEmpty();
	if (empty == true)
	{
		result = "true";
	}
	else
	{
		result = "false";
	}
	std::cout << result << std::endl;
	std::cout << "Stack testing complete." << std::endl;
}
