/*****************************************************************
** Program Filename: assignment2.cpp
** Author: Riley Brandau
** Date: 7/10/16
** Description: main method for assignment2
*****************************************************************/

//#include "stdafx.h"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <typeinfo>

void initializePtrs(Critter ***grid);
void displayGrid(Critter ***grid);
void deleteGrid(Critter ***grid);
void createAnts(Critter ***grid);
void createDoodles(Critter ***grid);
bool moveCritters(Critter ***grid, int row, int col);
void crittersEat(Critter ***grid, int x, int y);
void crittersDie(Critter ***grid, int x, int y);
void crittersBreed(Critter ***grid, int x, int y, int oX, int oY);

int main()
{
	srand(time(NULL)); //initialize random seed
	Critter ***grid;
	

	//Creating array of pointers to Critter pointers
	grid = new Critter**[20];
	for (int i = 0; i < 20; i++)
	{
		grid[i] = new Critter*[20];
	}
	
	//setting pointers to NULL
	initializePtrs(grid);

	std::cout << "grid before adding ants and doodlebugs" << std::endl;
	displayGrid(grid);

	
	//populating grid with 5 Doodlebugs and 100 ants
	//creating and placing Doodlebugs
	createDoodles(grid);

	//creating and placing Ants
	createAnts(grid);


	//print grid
	std::cout << "Grid after adding critters" << std::endl;
	displayGrid(grid);

	
	//loop through array for 100 steps
	for (int i = 0; i < 100; i++) //100 steps
	{
		for (int r = 0; r < 20; r++) //rows
		{
			for (int c = 0; c < 20; c++) //columns
			{
				//if cell != NULL, Call move function
				bool moved = false;
				moved = moveCritters(grid, r, c); //contains eat(), breed(), death()
	
			}
		}
		displayGrid(grid);
		std::cout << std::endl;
	}
	

	//delete memory
	deleteGrid(grid);


    return 0;
}

/*MAIN FUNCTIONS*/


/*****************************************************************
** Function:initializePtrs()
** Description: sets pointers to NULL
** Parameters: triple pointer to critter
*****************************************************************/
void initializePtrs(Critter ***grid)
{

	//setting pointers to NULL
	for (int r = 0; r < 20; r++)
	{
		for (int c = 0; c < 20; c++)
		{
			grid[r][c] = NULL;
		}
	}
}


/*****************************************************************
** Function: displayGrid()
** Description: prints out the array of pointers to critters
** Parameters: triple pointer to critter
*****************************************************************/
void displayGrid(Critter ***grid)
{
	for (int r = 0; r < 20; r++) //rows
	{
		for (int c = 0; c < 20; c++) //columns
		{
			
			if (grid[r][c] == NULL)
			{
				std::cout << "." << " "; 					
			}
		
			else if (typeid(*grid[r][c]) == typeid(Ant))
			{
				std::cout << "A" << " ";
			}
			else if (typeid(*grid[r][c]) == typeid(Doodlebug))
			{
				std::cout << "D" << " ";
			}
			else
			{
				std::cout << "." << " ";
			}

		}
		std::cout << std::endl;
	}
}


/*****************************************************************
** Function: deleteGrid()
** Description: frees memory
** Parameters: triple pointer to critter
*****************************************************************/
void deleteGrid(Critter ***grid)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			delete grid[i][j];
		}
		delete[] grid[i];
	}
	delete[] grid;
}


/*****************************************************************
** Function:createAnts()
** Description: randomly adds ant objects to the grid
** Parameters: triple pointer to critter
*****************************************************************/
void createAnts(Critter ***grid)
{
	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 18+1;
		int y = rand() % 18+1;
		Ant *critter;
		if (grid[y][x] == NULL) //place critter if spot is empty
		{
			critter = new Ant(y, x);
			grid[y][x] = critter;
		}
		std::cout << "Ant #" << i + 1 << std::endl;
		std::cout << "X = " << x << std::endl;
		std::cout << "Y = " << y << std::endl;

	}
}


/*****************************************************************
** Function:createDoodles
** Description: randomly adds doodlebug objects to the grid
** Parameters: triple pointer to critter
*****************************************************************/
void createDoodles(Critter ***grid)
{
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 18+1;
		int y = rand() % 18+1;
		Doodlebug *critter;
		if (grid[y][x] == NULL) //place critter if spot is empty
		{
			critter = new Doodlebug(y, x);
			grid[y][x] = critter;
		}
		std::cout << "Doodlebug #" << i + 1 << std::endl;
		std::cout << "X = " << x << std::endl;
		std::cout << "Y = " << y << std::endl;

	}
}


/*****************************************************************
** Function:moveCritters()
** Description: handles movement of critters
** Parameters: triple pointer to critter, 2 ints
*****************************************************************/
bool moveCritters(Critter ***grid, int row, int col)
{
	int y = row; 
	int x = col;
	int oX = x;
	int oY = y;
	bool moved = false;
	if (grid[x][y] != NULL)
	{
		int m = -1;
		m = grid[x][y]->move();
		//std::cout << m << std::endl;
		if (m == 0) //up
		{
			if ((grid[x][y-1] == NULL) && (y > 1)) //if spot is empty & not out of bounds move into spot. 
			{
				crittersEat(grid, x, y);
				grid[x][y-1] = grid[x][y];
				grid[x][y] = NULL; //make spot empty
				
				crittersBreed(grid, x, y-1, oX, oY);
				crittersDie(grid, x, y - 1);
				return true;
			}
			else
			{
				grid[x][y] = grid[x][y]; //no movement
				return false;
			}
		}
		if (m == 1) //right
		{
			if ((grid[x+1][y] == NULL) && (x < 18))
			{
				crittersEat(grid, x, y);
				grid[x+1][y] = grid[x][y];
				grid[x][y] = NULL;
				
				crittersBreed(grid, x+1, y, oX, oY);
				crittersDie(grid, x + 1, y);
				return true;
			}
			else
			{
				grid[x][y] = grid[x][y];
				return false;
			}
		}
		if (m == 2) //down
		{
			if ((grid[x][y+1] == NULL) && (y < 18))
			{
				crittersEat(grid, x, y);
				grid[x][y+1] = grid[x][y];
				grid[x][y] = NULL;
				
				crittersBreed(grid, x, y+1, oX, oY);
				crittersDie(grid, x, y + 1);
				
				return true;
			}
			else
			{
				grid[x][y] = grid[x][y];
				return false;
			}
		}
		if (m == 3) //left
		{
			if ((grid[x-1][y] == NULL) && (x > 1))
			{
				crittersEat(grid, x, y);
				grid[x-1][y] = grid[x][y];
				grid[x][y] = NULL;
			
				crittersBreed(grid, x-1, y, oX, oY);
				crittersDie(grid, x - 1, y);
				return true;
			}
			else
			{
				grid[x][y] = grid[x][y];
				return false;
			}

		}
	}
}


/*****************************************************************
** Function:crittersEat()
** Description: handles how critters eat
** Parameters: triple pointer to critter, 2 ints
*****************************************************************/
void crittersEat(Critter ***grid, int x, int y)
{
	bool hungry = false;
	if (typeid(*grid[x][y]) == typeid(Ant))
	{
		hungry = static_cast<Ant *>(grid[x][y])->eat();
		//std::cout << "ant ate" << std::endl;
	}
	else if (typeid(*grid[x][y]) == typeid(Doodlebug))
	{
		hungry = static_cast<Doodlebug *>(grid[x][y])->eat();
		//std::cout << "doodle ate" << std::endl;
	}
}


/*****************************************************************
** Function:crittersDie()
** Description: removes critter from grid if applicable
** Parameters: triple pointer to critter, 2 ints
*****************************************************************/
void crittersDie(Critter ***grid, int x, int y)
{
	bool dead = false;
	if (typeid(*grid[x][y]) == typeid(Ant))
	{
		dead = static_cast<Ant *>(grid[x][y])->death();
		if (dead == true)
		{
			grid[x][y] = NULL;
			//std::cout << "ant died" << std::endl;
		}
	}
	else if (typeid(*grid[x][y]) == typeid(Doodlebug))
	{
		dead = static_cast<Doodlebug *>(grid[x][y])->death();
		if (dead == true)
		{
			grid[x][y] = NULL;
			//std::cout << "Doodle died" << std::endl;
		}
	}
}


/*****************************************************************
** Function:crittersBreed()
** Description: adds a critter to the grid if applicable
** Parameters: triple pointer to critter, 4 ints
*****************************************************************/
void crittersBreed(Critter ***grid, int x, int y, int oX, int oY)
{
	bool breed = false;
	if (typeid(*grid[x][y]) == typeid(Ant))
	{
		Ant *aPtr;
		breed = static_cast<Ant *>(grid[x][y])->breed();
		if (breed == true)
		{
			aPtr = new Ant(oX, oY);
			grid[oX][oY] = aPtr;
			//std::cout << "ant had a baby" << std::endl;
		}
	}
	else if (typeid(*grid[x][y]) == typeid(Doodlebug))
	{
		Doodlebug *dPtr;
		breed = static_cast<Doodlebug *>(grid[x][y])->breed();
		if (breed == true)
		{
			dPtr = new Doodlebug(oX, oY);
			grid[oX][oY] = dPtr;
			//std::cout << "Doodle had a baby" << std::endl;
		}
	}
}
