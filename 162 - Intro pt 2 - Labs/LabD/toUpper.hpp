/*****************************************************************
** Program Filename: toUpper.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Header file for ToUpper class (Derived)
** makes lowercase letters upper case (eg: a -> A)
*****************************************************************/
//#pragma once

#ifndef TOUPPER_HPP
#define TOUPPER_HPP
#include "transformer.hpp"



class ToUpper :public Transformer
{
private:

public:
	ToUpper();
	~ToUpper();

	virtual char transform(char ch);
};

#endif
