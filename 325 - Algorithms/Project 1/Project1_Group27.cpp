// CS325 - Project 1 - Group 27
// Group Members: Matthew Yates, Riley Brandau, Anthony Tong
// Due 1/30/17
// Description: This program contains four algorithms that all solve the Maximum SubArray problem.

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
#include <tuple>
#include <climits>

int enumeration(std::vector<int>&nums, std::ofstream &outputFile);          //for writing to file
int betterEnumeration(std::vector<int> &nums, std::ofstream &outputFile);   //for writing to file
std::tuple<int, int, int> maxSubSum(std::vector<int> &nums, int low, int high);                   //for writing to file
std::tuple<int, int, int> maxOverlap(std::vector<int> &nums, int low, int mid, int high);         //for writing to file
int linearSubSum(std::vector<int> &nums, std::ofstream &outputFile);        //for writing to file

//int enumeration(std::vector<int>&nums);                                     //for timings
//int betterEnumeration(std::vector<int> &nums);                              //for timings
//int maxSubSum(std::vector<int> &nums, int low, int high);                   //for timings
//int maxOverlap(std::vector<int> &nums, int low, int mid, int high);         //for timings 
//int linearSubSum(std::vector<int> &nums);                                   //for timings

int max(int a, int b) { return (a > b) ? a : b; } 
int max(int a, int b, int c) { return max(max(a, b), c); }


int main()
{
	srand((unsigned int)time(NULL));
	int bestSum = 0;
	std::vector<int> testArray;
	int fileNum;

	//Generate test Arrays for Timing
	/*
	int randNum = 0; 
	int n = 500; //number of elements
	float time = 0.0;

	for (int i = 0; i < n; i++)
	{
		randNum = rand() % 101 + (-50); //generate numbers between -50 and 50
		testArray.push_back(randNum);
	}
	time = clock();
	enumeration(testArray);
	time = clock() - time;
	time = ((float)time) / CLOCKS_PER_SEC;
	std::cout << "Elements: " << n << " Time: " << time << std::endl;
	*/

	/*
		This block handles opening, reading, writing, and closing of the files.
	*/
	std::ifstream inputFile;
	inputFile.open("MSS_Problems.txt");
	std::ofstream outputFile;
	outputFile.open("MSS_Results.txt");
	if (!inputFile)
	{
		std::cout << "Error opening file..." << std::endl;
		return 1;
	}
	std::string row;
	while (std::getline(inputFile, row))
	{
		//std::cout << row << std::endl; //test to see if row was grabbed correctly
		std::stringstream stream(row);  //used for converting string to ints
		while (1)
		{
			stream >> fileNum;
			if (stream)                 //if an int was pushed into fileNum, add it to the array
			{
				testArray.push_back(fileNum);
			}
			else
			{
				break;
			}
		}
		outputFile << std::endl;
		bestSum = enumeration(testArray, outputFile);
		bestSum = betterEnumeration(testArray, outputFile);
		int low = 0;
		int high = testArray.size() - 1;
		std::tuple <int, int, int> DCBestSum = maxSubSum(testArray, low, high);
		bestSum = std::get<2>(DCBestSum);
		int start = std::get<0>(DCBestSum);
		int end = std::get<1>(DCBestSum);
		outputFile << "Alg 3 Best Sum: " << bestSum << ".\nFrom index [" << start << "] to [" << end << "]" << std::endl;
		for (int z = start; z <= end; z++)
		{
			outputFile << testArray[z] << " ";
		}
		outputFile << std::endl;
		bestSum = linearSubSum(testArray, outputFile);
		testArray.erase(testArray.begin(), testArray.end());
	
	}
	inputFile.close();
	outputFile.close();
    return 0;
}




//algorithms modified for writing to file

//Algorithm 1 - Enumeration (brute force)
int enumeration(std::vector<int> &nums, std::ofstream &outputFile)
{
	int start = 0;  //tracks the start of the largest subarray
	int end = 0;    //tracks the end of the largest subarray
	int length = nums.size(); //size of the array
	int bestSum = nums[0];    //sum of the largest subarray
	int currentSum = 0;       //sum of subarray being calculated

	for (int i = 0; i < length; i++) 
	{
		for (int j = i; j < length; j++)
		{
			currentSum = 0;
			for (int k = i; k <= j; k++)
			{
				currentSum += nums[k];
				if (currentSum > bestSum)
				{
					start = i;
					end = j;
					bestSum = currentSum;
				}
			}
		}
	}
	outputFile << "Alg 1 Best Sum: " << bestSum << ".\nFrom index [" << start << "] to [" << end << "]" << std::endl;
	for (int z = start; z <= end; z++)
	{
		outputFile << nums[z] << " ";
	}
	outputFile << std::endl;
	return bestSum;
}



//Algorithm 2 - Better Enumeration
int betterEnumeration(std::vector<int> &nums, std::ofstream &outputFile)
{
	int currentSum = 0;
	int bestSum = 0;
	int start = 0;
	int end = 0;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		currentSum = 0;
		for (int j = i; j < nums.size(); j++)
		{
			currentSum += nums[j];
			if (currentSum > bestSum)
			{
				start = i;
				end = j;
				bestSum = currentSum;
			}
		}
	}
	outputFile << "Alg 2 Best Sum: " << bestSum << ".\nFrom index [" << start << "] to [" << end << "]" << std::endl;
	for (int z = start; z <= end; z++)
	{
		outputFile << nums[z] << " ";
	}
	outputFile << std::endl;
	return bestSum;
}

//Algorithm 3 - Divide and Conquer
std::tuple<int, int, int> maxOverlap(std::vector<int> &nums, int low, int mid, int high)
{
	int currentSum = 0;
	int lowerSum = INT_MIN;
	int lowMax;
	for (int i = mid; i >= low; i--)
	{
		currentSum += nums[i];
		if (currentSum > lowerSum)
		{
			lowerSum = currentSum;
			lowMax = i;
		}
	}
	currentSum = 0;
	int upperSum = INT_MIN;
	int highMax;
	for (int j = mid + 1; j <= high; j++)
	{
		currentSum += nums[j];
		if (currentSum > upperSum)
		{
			upperSum = currentSum;
			highMax = j;
		}
	}
	return std::make_tuple(lowMax, highMax, (lowerSum + upperSum));
}

std::tuple<int, int, int> maxSubSum(std::vector<int> &nums, int low, int high)
{

	if (low == high)
	{
		return std::make_tuple(low, high, nums[low]);
		
	}
	
	int mid = (low + high) / 2;
	std::tuple<int, int, int> lower = maxSubSum(nums, low, mid);
	std::tuple<int, int,int> upper = maxSubSum(nums, mid + 1, high);
	std::tuple<int, int, int> middle = maxOverlap(nums, low, mid, high);

	if (max(std::get<2>(lower), std::get<2>(upper), std::get<2>(middle)) == std::get<2>(lower)) {
		return lower;
	}
	else if (max(std::get<2>(lower), std::get<2>(upper), std::get<2>(middle)) == std::get<2>(upper)) {
		return upper;
	}
	else {
		return middle;
	}

}


//Algorithm 4 - Linear
int linearSubSum(std::vector<int> &nums, std::ofstream &outputFile)
{
	int bestSum = INT_MIN;                 //setting bestSum to negative infinity, pretty much. 
	int currentSum = 0;                     //track subarray value                   
	int start = 0;                         //track start of subarray
	int end = 0;                           //track end of subarray
	int pos = 0;                           //track position in array


	for (int i = 0; i < nums.size(); i++)       //begin loop
	{
		currentSum = currentSum + nums[i];    //calculate array value

		if (bestSum < currentSum)        //determine if subarray is less than array value
		{
			bestSum = currentSum;        //if array > subarray, replace
			start = pos;                   //adjust starting position
			end = i;                       //adjust ending position
		}

		if (currentSum < 0)                 //if maxToHere took in an array val that made it < 0
		{
			currentSum = 0;                 //reset maxToHere to 0
			pos = i + 1;                   //set new position for subarray
		}
	}

	outputFile << "Alg 4 Best Sum: " << bestSum << ".\nFrom index [" << start << "] to [" << end << "]" << std::endl;
	for (int z = start; z <= end; z++)
	{
		outputFile << nums[z] << " ";
	}
	outputFile << std::endl;
	return bestSum;
}




//algorithms used for timings (unmodified). FINISHED
//Algorithm 1 - Enumeration (brute force)
/*
int enumeration(std::vector<int> &nums)
{
	int start = 0;  //tracks the start of the largest subarray
	int end = 0;    //tracks the end of the largest subarray
	int length = nums.size(); //size of the array
	int bestSum = nums[0];    //sum of the largest subarray
	int currentSum = 0;       //sum of subarray being calculated

	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			currentSum = 0;
			for (int k = i; k <= j; k++)
			{
				currentSum += nums[k];
				if (currentSum > bestSum)
				{
					start = i;
					end = j;
					bestSum = currentSum;
				}
			}
		}
	}
	return bestSum;
}



//Algorithm 2 - Better Enumeration
int betterEnumeration(std::vector<int> &nums)
{
	int currentSum = 0;
	int bestSum = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		currentSum = 0;
		for (int j = i; j < nums.size(); j++)
		{
			currentSum += nums[j];
			if (currentSum > bestSum)
			{
				start = i;
				end = j;
				bestSum = currentSum;
			}
		}
	}
	return bestSum;
}

//Algorithm 3 - Divide and Conquer
int maxOverlap(std::vector<int> &nums, int low, int mid, int high)
{
	int currentSum = 0;
	int lowerSum = INT_MIN;
	for (int i = mid; i >= low; i--)
	{
		currentSum += nums[i];
		if (currentSum > lowerSum)
		{
			lowerSum = currentSum;
		}
	}
	currentSum = 0;
	int upperSum = INT_MIN;
	for (int j = mid + 1; j <= high; j++)
	{
		currentSum += nums[j];
		if (currentSum > upperSum)
		{
			upperSum = currentSum;
		}
	}
	return lowerSum + upperSum;
}

int maxSubSum(std::vector<int> &nums, int low, int high)
{
	if (low == high)
	{
		return nums[low];
	}
	int mid = (low + high) / 2;
	return max(maxSubSum(nums, low, mid),
		maxSubSum(nums, mid + 1, high),
		maxOverlap(nums, low, mid, high));
}


//Algorithm 4 - Linear
int linearSubSum(std::vector<int> &nums)
{
	int bestSum = INT_MIN;                 //setting bestSum to negative infinity, pretty much. 
	int currentSum = 0;                     //track subarray value                   
	int start = 0;                         //track start of subarray
	int end = 0;                           //track end of subarray
	int pos = 0;                           //track position in array


	for (int i = 0; i < nums.size(); i++)       //begin loop
	{
		currentSum = currentSum + nums[i];    //calculate array value

		if (bestSum < currentSum)        //determine if subarray is less than array value
		{
			bestSum = currentSum;        //if array > subarray, replace
			start = pos;                   //adjust starting position
			end = i;                       //adjust ending position
		}

		if (currentSum < 0)                 //if maxToHere took in an array val that made it < 0
		{
			currentSum = 0;                 //reset maxToHere to 0
			pos = i + 1;                   //set new position for subarray
		}
	}
	return bestSum;
}
*/
