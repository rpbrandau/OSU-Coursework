/*****************************************************************
** Program Filename: orderedOutput.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Header file for OrderedOutput class (Derived)
** Splits text into groups of 5 chars (eg: abcdefghij -> abcde fghij)
*****************************************************************/
//#pragma once

#ifndef ORDEREDOUTPUT_HPP
#define ORDEREDOUTPUT_HPP
#include "transformer.hpp"
#include "orderedOutput.hpp"

class OrderedOutput : public Transformer
{
private:
	int position = 1;
public:
	OrderedOutput();
	~OrderedOutput();
	
	virtual char transform(char ch);
};

#endif
