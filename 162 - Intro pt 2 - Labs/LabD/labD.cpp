/*****************************************************************
** Program Filename: labD.cpp
** Author: Riley Brandau - brandaur@oregonstate.edu
** Date: 7/14/16
** Description: Main method for demonstrating derived classes
*****************************************************************/

//#include "stdafx.h"
#include "transformer.hpp"
#include "copy.hpp"
#include "encryption.hpp"
#include "orderedOutput.hpp"
#include "toUpper.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int key;
	std::ifstream input;
	std::ofstream copyF, encryptedF, ordOutF, toUpperF, comboF;
	ToUpper upper;
	Copy paste;
	OrderedOutput orderedOut;
	std::string inputFileName, copyOut, encryptOut, ordOut, upperOut, combo;
	
	std::cout << "Please enter name of file to open..." << std::endl;
	std::cin >> inputFileName;
	input.open(inputFileName.c_str());
	while (input.fail())
	{
		std::cout << std::endl;
		std::cout << "File can not be opened." << std::endl;
		std::cout << "Please enter valid filename..." << std::endl;
		std::cin >> inputFileName;
		input.open(inputFileName.c_str());
	}

	


	std::cout << "A series of transformations will be performed on the contents of this file." << std::endl;
	std::cout << "It will remain unchanged, but the transformations will be written to a new file." << std::endl;
	std::cout << "Please enter the name of the file to demonstrate the COPY feature..." << std::endl;
	std::cin >> copyOut;
	copyF.open(copyOut.c_str());
	std::cout << "Please enter the name of the file to demonstrate the ENCRYPTION feature..." << std::endl;
	std::cin >> encryptOut;
	encryptedF.open(encryptOut.c_str());
	std::cout << "Please enter the name of the file to demonstrate the ORDEREDOUTPUT feature..." << std::endl;
	std::cin >> ordOut;
	ordOutF.open(ordOut.c_str());
	std::cout << "Please enter the name of the file to demonstrate the TOUPPER feature..." << std::endl;
	std::cin >> upperOut;
	toUpperF.open(upperOut.c_str());
	std::cout << "Please enter an integer to be used as a key for encryption..." << std::endl;
	std::cin >> key;

	Encryption encrypt(key);

	//perform transformations and write to files
	paste.doFilter(input, copyF);
	input.close();
	input.open(inputFileName.c_str());
	encrypt.doFilter(input, encryptedF);
	input.close();
	input.open(inputFileName.c_str());
	orderedOut.doFilter(input, ordOutF);
	input.close();
	input.open(inputFileName.c_str());
	upper.doFilter(input, toUpperF);
	input.close();

	//need to take input, pass it to encrypt, take that output pass it to orderedOut, take that output and pass it to toUpper
	std::cout << "A file called 'combo.txt' has been created to combine all of these tests. '\n' (copy -> encrypt -> orderdOut -> toUpper)." << std::endl;
	combo = "combo.txt";
	paste.doFilter(input, comboF);
	input.close();
	input.open(combo.c_str());
	encrypt.doFilter(input, comboF);
	input.close();
	input.open(combo.c_str());
	orderedOut.doFilter(input, comboF);
	input.close();
	input.open(combo.c_str());
	upper.doFilter(input, comboF);
	input.close();


	//close input and output files
	input.close();
	copyF.close();
	encryptedF.close();
	ordOutF.close();
	toUpperF.close();
	comboF.close();
	





    return 0;
}

