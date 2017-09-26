/*****************************************************************
** Program Filename: loadedDice.hpp
** Author: Riley Brandau
** Date: 6/29/16
** Description: header file for loadedDice derived class
*****************************************************************/
//#pragma once

#ifndef LOADEDDICE_HPP
#define LOADEDDICE_HPP

class LoadedDice : public Dice
{
public:
	LoadedDice();
	LoadedDice(int);
	int roll();
};
#endif // !LOADEDDICE_H
