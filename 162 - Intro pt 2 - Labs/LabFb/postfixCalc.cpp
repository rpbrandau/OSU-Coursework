/*****************************************************************
** Program Filename: postfixCalc.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/8/16
** Description: Source file for postfixCalc functions
*****************************************************************/
//#include "stdafx.h"
#include "postfixCalc.hpp"


/*****************************************************************
** Function: isOp()
** Description: checks input to see if it is an operator
** Parameters: char
*****************************************************************/
bool isOp(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*****************************************************************
** Function: doOp()
** Description: performs operation on two operands
** Parameters: int, int, char
*****************************************************************/
int doOp(int opRand1, int opRand2, char opRator)
{
	int result;

	switch (opRator)
	{
	case '+':
		result = opRand2 + opRand1;
		break;
	case '-':
		result = opRand2 - opRand1;
		break;
	case '*':
		result = opRand2 * opRand1;
		break;
	case '/':
		result = opRand2 / opRand1;
		break;
	}
	return result;
}
