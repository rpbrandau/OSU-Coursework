/*****************************************************************
** Program Filename: labG.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 8/7/16
** Description: Driver for testing binary search, bubble sort, and linear search functions
*****************************************************************/

//#include "stdafx.h"
#include "linearSearch.hpp"
#include "binarySearch.hpp"
#include "bubbleSort.hpp"
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <string>
#include <fstream>

int intCount(std::ifstream &file);

int main()
{
	int size = 0; //holds size of array
	int searchFor = -1; //hold user input for search
	int result = -1; //stores value of search functions
	int *intArray = NULL; //pointer for dynamic array
	int choice = 0; //menu choice
	std::ifstream input; //read from this file
	std::ofstream output; //write to this file
	std::string inputFile; //input filename
	std::string outputFile; //output filename


	while (choice != 4)
	{
		std::cout << "1 = Linear Search\n2 = Bubble Sort\n3 = Binary Search\n4 = Exit Program" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1: //1 - search for target value - linear search
		{
			//prompt user for input file
			std::cout << "Please enter filename to perform a linear search on: ";
			std::cin >> inputFile; //store filename
			input.open(inputFile.c_str()); //open file
			if (!input)
			{
				std::cout << "File could not be opened." << std::endl;
			}
			else
			{
				std::cout << "File open successfully. Copying data into array..." << std::endl;
				size = intCount(input); //get how many integers are in file
				//input.close(); //workaround for resetting the EOF flag
				//input.open(inputFile.c_str()); //workaround for resetting the EOF flag
				intArray = new int[size]; //create dynamic array

				//initialize array
				for (int i = 0; i < size; i++)
				{
					intArray[i] = 0;
				}

				//read input into array
				for (int i = 0; i < size; i++)
				{
					input >> intArray[i];
				}

				//display array/input
				for (int i = 0; i < size; i++)
				{
					std::cout << intArray[i] << std::endl;
				}
				//prompt user for value to search for
				std::cout << "What number would you like to search for?" << std::endl;
				std::cin >> searchFor;
				std::cout << "Searching the list for " << searchFor << "..." << std::endl;
				//perform linear search
				result = linearSearch(intArray, searchFor, size);

				//display results
				if (result == -1) //if not found
				{
					std::cout << "The number " << searchFor << " was not found." << std::endl;
				}
				else //if found
				{
					std::cout << "The number " << searchFor << " was found at position " << result + 1 << " in the list." << std::endl;
				}
				input.close();
				delete intArray;
			}
		} 
		break;
		case 2: //2 - sort set of values - bubble sort
		{
			//prompt user for input file
			std::cout << "Please enter filename to perform a Bubble Sort on: ";
			std::cin >> inputFile; //store filename
			input.open(inputFile.c_str()); //open file
			if (!input)
			{
				std::cout << "File could not be opened." << std::endl;
			}
			else
			{
				std::cout << "File open successfully. Copying data into array..." << std::endl;
				size = intCount(input); //get how many integers are in file
				intArray = new int[size]; //create dynamic array

				//read input into array
				for (int i = 0; i < size; i++)
				{
					input >> intArray[i];
				}
				
				std::cout << "array before sort" << std::endl;
				for (int i = 0; i < size; i++)
				{
					std::cout << intArray[i] << std::endl;
				}
				//perform sort
				bubbleSort(intArray, size);
				std::cout << "array after sort" << std::endl;
				for (int i = 0; i < size; i++)
				{
					std::cout << intArray[i] << std::endl;
				}
				//prompt user for output file
				std::cout << "Please enter filename to write to: ";
				std::cin >> outputFile;
				output.open(outputFile.c_str());
				//write sorted array into output file
				for (int i = 0; i < size; i++)
				{
					output << intArray[i] << std::endl;
				}
				std::cout << "Data written to file." << std::endl;
				output.close();
				input.close();
				delete intArray;
			}
		}
		break;
		case 3: //3 - search for target value - binary search
		{
			//prompt user for a sorted list file (should be output of bubble sort)
			std::cout << "Please enter a filename of a sorted list to perform a Binary Search on: ";
			std::cin >> inputFile;
			input.open(inputFile.c_str());
			if (!input)
			{
				std::cout << "Could not open file." << std::endl;
			}
			else
			{
				std::cout << "File open successfully. Copying data into array..." << std::endl;
				size = intCount(input); //get how many integers are in file
				intArray = new int[size]; //create dynamic array

				//read input into array
				for (int i = 0; i < size; i++)
				{
					input >> intArray[i];
				}
				std::cout << "list:" << std::endl;
				for (int i = 0; i < size; i++)
				{
					std::cout << intArray[i] << std::endl;
				}
				//prompt user for a value to search for
				std::cout << "What number would you like to search for?" << std::endl;
				std::cin >> searchFor;
				//perform search
				result = binarySearch(intArray, size, searchFor);
				
				//display results
				if (result == -1) //if not found
				{
					std::cout << "The number " << searchFor << " was not found." << std::endl;
				}
				else //if found
				{
					std::cout << "The number " << searchFor << " was found at position " << result + 1 << " in the list." << std::endl;
				}
				input.close();
				delete intArray;
			}
		}
		break;
		case 4: //4 - Exit menu/program
			break;
		}//end of switch

	}//end of while
		
    return 0;
}


/*****************************************************************
** Function: intCount()
** Description: returns how many integers are in a text file
** Parameters: reference to text file
** Source1: en.cppreference.com/w/cpp/iterator/istreambuf_iterator
** Source2: stackoverflow.com/questions/7681555/resetting-the-end-of-file-state-of-a-ifstream-object-in-c (for resetting the EOF flag...) 
*****************************************************************/
int intCount(std::ifstream &file)
{
	int count = 0;

	std::istream_iterator<int> start(file), end;
	count = std::distance(start, end);
	file.clear();
	file.seekg(0, std::ios::beg);
	
	return count;
}
