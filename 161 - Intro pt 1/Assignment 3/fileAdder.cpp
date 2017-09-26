/**********
 * Author: Riley Brandau
 * Date: 1/19/16
 * Description: Assignment 3.b - Write a program that prompts the user for the name of a file and then tries to open it. If the input file is there and can be opened, the program will read the list of integers and add them together. It will then open an output file called "sum.txt" and write the total to that file. The program will close both files before quitting. If either file is missing, an error message will be displayed.
 *
 * instead of using the C++ method for opening files, we are to use a C-style string. example: inputFile.open(filename.c_str())
 
**********/

#include <iostream>
#include <fstream> //needed for reading and writing to files
#include <string>

using namespace std;

int main()
{
	ifstream inputFile; //needed for reading the input file
	ofstream outputFile; //needed for creating/writing to the output file

	string filename; //needed for the c_str() argument
	
	int number,
	    total;


//get file name from user and attempt opening input file
	cout << "Please enter filename:" << endl;
	cin >> filename; 
	inputFile.open(filename.c_str());

//if the file is found, process the file, then close it
	if (inputFile)
	{
		while (inputFile >> number)
		{
		total = total + number; //summing the numbers in the file
		}
	
	inputFile.close(); //closing the file
	}

	else //display error message if file is not found
	{
		cout << "Error opening the file." << endl;
	}

//Attempt to open the output file "sum.txt"
	outputFile.open("sum.txt"); //try using outputFile.open("sum.txt"); if this doesnt work

//if the file is found, write the total to it and then close it
	if (outputFile)
	{
		outputFile << total;
		outputFile.close();
	}

//if the file is not found, display error message
	else
	{
		cout << "Could not access file." << endl;
	}

return 0;
}

