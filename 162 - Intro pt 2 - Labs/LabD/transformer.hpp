/*****************************************************************
** Program Filename: transformer.hpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Header file for Transformer class
** Abstract Base Class
*****************************************************************/
//#pragma once

#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP
#include <iostream>
#include <fstream>


class Transformer
{
public:
	Transformer();
	~Transformer();
	virtual void doFilter(std::ifstream &in, std::ofstream &out);
	virtual char transform(char ch) = 0;

};


#endif
