/**************************************************
Author: Riley Brandau
Date: 3/2/16
Description: This is a headerfile for a class called Board
**************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

using namespace std;

enum WinCon {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
		char boardArr[][3]; //each element should be initialized to "." . Replace "." with "x" or "o" if move if successful
		int turn;	

public:
		Board(); //initializes each element to "."
		bool makeMove(int, int, int); //this should replace "." with "x" or "o". It should check if the move is valid. 
														  //It should switch the turn after a successful turn is made.
		
		WinCon gameState(); //This should be called after each successful move to check if the game was won/draw/unfinished
		void print(); //displays current board. Should be called after each successful move. Will need to make sure they line up correctly.
};
#endif
