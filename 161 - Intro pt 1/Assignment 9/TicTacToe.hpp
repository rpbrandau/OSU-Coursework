/*****************************************************
Author: Riley Brandau
Date: 3/2/16
Description: This is the header file for a class called TicTacToe
****************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

using namespace std;

class TicTacToe
{
private:
	Board game; //board object. Board contains a char array[][]
	int turn; //keeps track of whose turn it is. 
	char c;
	
public:
	TicTacToe(char); //determines if X or O goes first
	void play(); // starts the game. Asks whichever player gets to go first (as chosen in main) to make a move.
			 //Loops - asks player for their move. Stops when there is a win or draw. Prints outcome.
};
#endif
