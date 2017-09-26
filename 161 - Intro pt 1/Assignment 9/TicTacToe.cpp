/*****************************************************
Author: Riley Brandau
Date: 3/2/16
Description: This contains the definitions for TicTacToe as well as a main
method for playing the game.
However, I ran out of time for this assignment, so while it compiles, it does
not behave as it should. Wrote the code in notepad++ and uploaded to flip via
filezilla - lots of the formatting was lost.
*****************************************************/

#include "Board.hpp"
#include "TicTacToe.hpp"
#include <iostream>
using namespace std;

/*******************************************************
		TICTACTOE METHODS
********************************************************/

/***********************************
	TicTacToe constructor
***********************************/

TicTacToe::TicTacToe(char choice)
{
  char c = choice;
	
  if (c == 'x' || 'X')
   {
      cout << "X will make the first play." << endl;
   }
  else if (c == 'o' || 'O')
   {
      cout << "O will make the first play." << endl;
   }
   else
      cout << "Please enter 'X' or 'O'." << endl;
}

/***********************************
	play() method
***********************************/
void TicTacToe::play()
{
   int turn = 0;
   char x, y;
   Board game;	
   game.print();
	
   for (int pass = 0; pass < 10; pass++)
      {
	if (c == 'x' || c == 'X')
	   cout << "Player X, please enter your move: " << endl;
	else if (c == 'o' || c == 'O')
	   cout << "Player O, please enter your move: " << endl;
			
	cin >> x, y;
	game.makeMove(x,y,turn);
			
	if (game.gameState() == 3) //the game is UNFINISHED
	   {
	      if (turn %2 == 0) //player X
		{
		   cout << "Player X: Please enter your move: " << endl;
		   cin >> x, y;
		   if(game.makeMove(x,y,turn) == true)
			turn++;
		   else
		      {
			cout << "That space is taken. Make a valid move: " << endl;
			cin >> x, y;
			game.makeMove(x,y,turn);
		      }
		}
	      else
		{
		   cout << "Player O: Please enter your move: " << endl;
		   cin >> x, y;
		   if(game.makeMove(x,y,turn) == true)
		      turn++;
		   else
		      {
			cout << "That space is taken. Make a valid move: " <<endl;
			cin >> x, y;
			game.makeMove(x,y,turn);
		      }
		}
	   }
	else
	   {
	      if(game.gameState() == 0)
		{
		   cout << "Player X Won!" << endl;
		}
	      else if(game.gameState() == 1)
		{
		   cout << "Player O Won!" << endl;
		}
	      else
		{
		   cout << "Game was a Draw." << endl;
		}
	   }
		
      }
	
	
}


/*******************************************************
								MAIN METHOD
*******************************************************/

int main()
{	
	char c;
	cout << "Who shall play first, 'x' or 'o' ?" << endl;
	cin >> c;
	Board game;

	
	TicTacToe(c).play();	
	
	return 0;
	
};
