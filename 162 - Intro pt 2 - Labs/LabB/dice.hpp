/*****************************************************************
** Program Filename: dice.hpp
** Author: Riley Brandau
** Date: 6/29/16
** Description: header file for dice class
*****************************************************************/
//#pragma once
#ifndef DICE_HPP
#define DICE_HPP

class Dice
{
protected:
	int sides;
public:
	Dice();
	Dice(int);
	int roll();
};
#endif // !DICE_H
