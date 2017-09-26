/*****************************************************************
** Program Filename: labC.cpp
** Author: Riley Brandau
** Date: 7/6/16
** Description: reverses input file contents
** Input: file (string)
** Output: reverse of input file
*****************************************************************/

//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

void reverseCharArray(char *arr, std::ofstream &output);

int main()
{
	std::ifstream inputFile; //read from this
	std::ofstream outputFile; //output to this
	std::string inFileName; 
	std::string outFileName; 
	char *cArray;
	int arraySize = 50;
	int counter = 0;


	//creating dynamic array
	cArray = new char[arraySize];
	//initializing pointers to NULL
	for (int i = 0; i < arraySize; i++)
	{
		cArray[i] = NULL;
	}
	//ask user for input filename
	std::cout << "Please enter filename to read from: " << std::endl; //test.txt
	std::cin >> inFileName;
	inputFile.open(inFileName.c_str());
	//ask user for output filename
	std::cout << "Please enter filename to write to: " << std::endl; //output.txt
	std::cout << "(If one isn't found, one will be created)" << std::endl;
	std::cin >> outFileName;
	outputFile.open(outFileName.c_str());
	
	//read contents of file if open and copy it into array.
	if (inputFile)
	{
		std::cout << "File opened Successfully. Now copying data into array..." << std::endl;
		while ((!inputFile.eof()) && (counter < arraySize))
		{
			inputFile.get(cArray[counter]);
			counter++;
		}
		cArray[counter - 1] = '\0';
		std::cout << "Displaying contents of array..." << std::endl;
		for (int i = 0; cArray[i] != '\0'; i++)
		{
			std::cout << cArray[i];
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "File could not be opened." << std::endl;
	}

	//reverse array using recursive function & write to output file
	reverseCharArray(cArray, outputFile);
	
	
	//close inputfile
	inputFile.close();
	//close outputfile
	outputFile.close();
	//deleting dynamic array
	delete[] cArray;

    return 0;
}



/*****************************************************************
** Function: reverseCharArray()
** Description: reverses an array of Chars and writes them to an output file
** Parameters: pointer to char, reference to output file
*****************************************************************/
void reverseCharArray(char *arr, std::ofstream &output)
{
	if (*arr == '\0') //base case
	{
		return;
	}
	else //recursive case
	{
		reverseCharArray(arr + 1, output);
		std::cout << *arr;
		output << *arr;  //writing to output file.
	}
}
