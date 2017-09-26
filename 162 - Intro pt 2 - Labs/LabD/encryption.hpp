/*****************************************************************
** Program Filename: encryption.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Header file for Encryption class (Derived)
** Performs Caesar Cipher-type encryption 
*****************************************************************/
//#pragma once

#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP
#include "transformer.hpp"


class Encryption : public Transformer
{
private:
	int key;

public:
	Encryption(int k);
	~Encryption();
	
	virtual char transform(char ch);


};
#endif // !ENCRYPTION_HPP
