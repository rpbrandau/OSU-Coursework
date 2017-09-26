/*****************************************************************
** Program Filename: transformer.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Source file for Transformer class
*****************************************************************/
//#include "stdafx.h"
#include "transformer.hpp"


/*****************************************************************
** Function: Transformer()
** Description: Constructor
** Parameters: none
*****************************************************************/
Transformer::Transformer()
{

}


/*****************************************************************
** Function: ~Transformer()
** Description: Destructor
** Parameters: none
*****************************************************************/
Transformer::~Transformer()
{

}


/*****************************************************************
** Function: doFilter()
** Description: takes input, performs a transformation on it
** then outputs it to a new file.
** Parameters: input stream object, output stream object
** Source: adapted from text book
*****************************************************************/
void Transformer::doFilter(std::ifstream &in, std::ofstream &out)
{
	char ch;
	char modCh;
	in.get(ch);

	while (!in.fail())
	{
		modCh = transform(ch);
		out.put(modCh);
		in.get(ch);
	}
}
