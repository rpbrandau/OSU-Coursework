/********************************************************
Author: Riley Brandau
Date: 3/2/16
Description: This is the definition file for a class called Board
********************************************************/

#include "Board.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************
			Board Array
*********************************************************/
Board::Board()
{
	const int ROW = 3;
	const int COL = 3;
	
	for (int i = 0; i < 3; i++) // loop to set all board spaces to "."
	{
		boardArr[0][i] = '.'; //0,0; 0,1; 0,2
		boardArr[1][i] = '.'; //1,0; 1,1; 1,2
		boardArr[2][i] = '.'; //2,0; 2,1; 2,2
	}
	
}


/********************************************************
		makeMove() Function
********************************************************/
bool Board::makeMove(int xPos, int yPos, int turnNum) 
{
	int x = xPos;
	int y = yPos;
	int turn = turnNum;

	
	if (turn %2 == 0) // For Even numbers x = even turn
	   {
			if (boardArr[x][y] == '.') //successful move
					{
						boardArr[x][y] = 'x';
						gameState();
						turn++; 
						print();
						return true;
					}
				else
					{
						return false;
					}
	    }	
	 else //turn is odd, o = odd turn
		{
				if (boardArr[x][y] == '.') //successful move
					{
						boardArr[x][y] = 'o';
						gameState();
						turn++;
						print();
						return true;
					}
				else
					{
						return false;
					}
		}
}
/********************************************************
 * 		gameState() Function
********************************************************/
WinCon Board::gameState()
{
	
	if (turn %2 == 0)  //X just made a move, checking for win
	{
		if (boardArr[0][0] == 'x' && boardArr[0][1] == 'x' && boardArr[0][2] == 'x')  //top row
			return X_WON;
		else if (boardArr[1][0] == 'x' && boardArr[1][1] == 'x' && boardArr[1][2] == 'x') //mid row
			return X_WON;
		else if (boardArr[2][0] == 'x' && boardArr[2][1] == 'x' && boardArr[2][2] == 'x') //bot row
			return X_WON;
		else if (boardArr[0][0] == 'x' && boardArr[1][0] == 'x' && boardArr[2][0] == 'x') //left col
			return X_WON;
		else if (boardArr[0][1] == 'x' && boardArr[1][1] == 'x' && boardArr[2][2] == 'x') //mid col
			return X_WON;
		else if (boardArr[0][2] == 'x' && boardArr[1][2] == 'x' && boardArr[2][2] == 'x') //right col
			return X_WON;
		else if (boardArr[0][0] == 'x' && boardArr[1][1] == 'x' && boardArr[2][2] == 'x') //L to R diag
			return X_WON;
		else if (boardArr[0][2] == 'x' && boardArr[1][1] == 'x' && boardArr[2][0] == 'x') //R to L diag
			return X_WON;
		else
				if (turn == 9)
					return DRAW;
				else
					return UNFINISHED;
	}	
	else  //O just made a move, checking for win
	{
		if (boardArr[0][0] == 'o' && boardArr[0][1] == 'o' && boardArr[0][2] == 'o')  //top row
			return O_WON;
		else if (boardArr[1][0] == 'o' && boardArr[1][1] == 'o' && boardArr[1][2] == 'o') //mid row
			return O_WON;
		else if (boardArr[2][0] == 'o' && boardArr[2][1] == 'o' && boardArr[2][2] == 'o') //bot row
			return O_WON;
		else if (boardArr[0][0] == 'o' && boardArr[1][0] == 'o' && boardArr[2][0] == 'o') //left col
			return O_WON;
		else if (boardArr[0][1] == 'o' && boardArr[1][1] == 'o' && boardArr[2][2] == 'o') //mid col
			return O_WON;
		else if (boardArr[0][2] == 'o' && boardArr[1][2] == 'o' && boardArr[2][2] == 'o') //right col
			return O_WON;
		else if (boardArr[0][0] == 'o' && boardArr[1][1] == 'o' && boardArr[2][2] == 'o') //L to R diag
			return O_WON;
		else if (boardArr[0][2] == 'o' && boardArr[1][1] == 'o' && boardArr[2][0] == 'o') //R to L diag
			return O_WON;
		else
				if (turn == 9)
					return DRAW;
				else
					return UNFINISHED;
	}
	
}


/*********************************************************
		print() Function
*********************************************************/
void Board::print()
{
		cout << " " << endl;
		cout << " " << setw(3) <<      "0"    <<     setw(3) <<       "1"      << setw(3) <<          "2"   << endl; //Row 0
		cout << "0" << setw(3) <<  boardArr[0][0] << setw(3) << boardArr[0][1] << setw(3) << boardArr[0][2] << endl; //Row 1
		cout << "1" << setw(3) <<  boardArr[1][0] << setw(3) << boardArr[1][1] << setw(3) << boardArr[1][2] << endl; //Row 2
		cout << "2" << setw(3) <<  boardArr[2][0] << setw(3) << boardArr[2][1] << setw(3) << boardArr[2][2] << endl; //Row 3
		cout << endl;
}

							
