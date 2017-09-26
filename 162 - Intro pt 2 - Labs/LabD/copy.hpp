/*****************************************************************
** Program Filename: copy.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Header file for Copy class
** Derived Class. Copies data as is.
*****************************************************************/
//#pragma once

#ifndef COPY_HPP
#define COPY_HPP
#include "transformer.hpp"

class Copy : public Transformer
{
private:

public:
	Copy();
	~Copy();

	virtual char transform(char ch);
};

#endif // !COPY_HPP
