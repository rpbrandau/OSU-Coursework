/*****************************************************************
** Program Filename: encryption.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Source file for encryption class
*****************************************************************/
//#include "stdafx.h"
#include "encryption.hpp"


/*****************************************************************
** Function: Encryption()
** Description: Constructor. Sets key to passed int
** Parameters: int
*****************************************************************/
Encryption::Encryption(int k)
{
	key = k;
}


/*****************************************************************
** Function: ~Encryption()
** Description: Destructor
** Parameters: none
*****************************************************************/
Encryption::~Encryption()
{

}


/*****************************************************************
** Function: transform()
** Description: performs a ceasar cipher shift based on user key
** Parameters: char variable
*****************************************************************/
char Encryption::transform(char ch)
{
	char x = ' ';
	int k = key;

	if (((int)ch > 64) && ((int)ch < 91)) //uppercase letters = 65-90
	{
		x = (((ch - 65) + k) % 26) + 65;
		return x;
	}
	else if (((int)ch > 96) && ((int)ch < 123)) //lowercase letters = 97-122
	{
		x = (((ch - 97) + k) % 26) + 97;
		return x;
	}
	else //not a upper or lowercase letter (punctuation, etc)
	{
		x = ch;
		return x;
	}
}

