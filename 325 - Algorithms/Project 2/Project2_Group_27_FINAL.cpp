/***********************************************************************************

** Author:      David Yates, Riley Brandau, Ian O'Leary

** Date:        1/31/17

** Description: CS 325 - Project 2 - Group 27

************************************************************************************/
#include <ctime>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;
vector<int> changedp(vector<int> &nums, int totalCoins, int targetChange);
int changeslow(vector<int> &nums, vector<int> &solution, int numOfCoins, int coinVal);
vector<int> changegreedy(vector<int> &nums, int totalCoins, int targetChange);
void vectorOutput(vector<float> &input, int inputSize, ofstream * outputFile);
void vectorOutput(vector<int> &input, int inputSize, ofstream * outputFile);

int main(int argc, char *argv[])
{
	
	if (argc != 2) {
		//No input file declaration
		cout << "This program requires one argument. Try again." << endl;
		return 1;
	}
	string inputPath = argv[1];
	string outputPath = argv[1];
	inputPath = inputPath + ".txt"; 
	outputPath = outputPath + "change.txt";
	std::ofstream outputFile;
	std::ifstream inputFile;  //for passing the file name as argument from the command line
	inputFile.open(inputPath);
	outputFile.open(outputPath);

	if (!inputFile)
	{
		std::cout << "Error opening file..." << std::endl;
		return 1;
	}
	std::string row;
	int lineNumber = 0;
	int currentChange = 0;
	int targetChange = 0;
	vector<int> coinsAvailable;
	vector<int> coinsUsed;
	int minCoins;

	while (getline(inputFile, row))
	{
		std::stringstream stream(row);  //used for converting string to ints
		int fileNum = 0;
		lineNumber++;
		if (lineNumber % 2 != 0)
		{
			while (stream >> fileNum)
			{
				coinsAvailable.push_back(fileNum);
			}
		}
		else
		{
			stream >> fileNum;
			targetChange = fileNum;

			//greedy algo
			minCoins = INT_MAX;
			coinsUsed = changegreedy(coinsAvailable, coinsAvailable.size(), targetChange);
			minCoins = accumulate(coinsUsed.begin(), coinsUsed.end() - 1, 0);
			coinsUsed.pop_back();
			//write results to file
			outputFile << "changegreedy alogorithm: " << endl;
			vectorOutput(coinsAvailable, coinsAvailable.size(), &outputFile);
			vectorOutput(coinsUsed, coinsUsed.size(), &outputFile);
			outputFile << minCoins << endl;
			outputFile << std::endl;
			coinsUsed.clear();

			//dynamic algo
			minCoins = INT_MAX;
			coinsUsed = changedp(coinsAvailable, coinsAvailable.size(), targetChange);
			minCoins = coinsUsed[coinsUsed.size()-1];
			coinsUsed.pop_back();
			outputFile << "changedp alogorithm: " << endl;
			vectorOutput(coinsAvailable, coinsAvailable.size(), &outputFile);
			vectorOutput(coinsUsed, coinsAvailable.size(), &outputFile);
			outputFile << minCoins << endl;
			outputFile << std::endl;
			coinsUsed.clear();

			//slow algo
			minCoins = INT_MAX;
			vector<int> coinsUsed(coinsAvailable.size());
			minCoins = changeslow(coinsAvailable, coinsUsed, coinsAvailable.size(), targetChange);
			outputFile << "changeslow alogorithm: " << endl;
			vectorOutput(coinsAvailable, coinsAvailable.size(), &outputFile);
			vectorOutput(coinsUsed, coinsAvailable.size(), &outputFile);
			outputFile << minCoins << endl;
			outputFile << std::endl;
			coinsUsed.clear();

			coinsAvailable.clear();
		}

	}
	return 0;
}

vector<int> changedp(vector<int> &nums, int totalCoins, int targetChange) {

	vector<int> solution(targetChange + 1);
	vector<int> coinsArray(totalCoins);
	fill(coinsArray.begin(), coinsArray.end(), 0);
	fill(solution.begin(), solution.end(), INT_MAX - 1); 

	solution[0] = 0;
	int coin = 0;

	for (int i = 1; i <= targetChange; i++) {

		for (int j = 0; j < totalCoins; j++) {
			if (nums[j] <= i) {
				int temp = solution[i - nums[j]];
				if (temp != INT_MAX - 1 && temp + 1 < solution[i]) {
					solution[i] = temp + 1;
					coinsArray[j]++;
				}
			}
		}
	}
	coinsArray.push_back(solution[targetChange]);
	return coinsArray;
}

int changeslow(vector<int> &nums, vector<int> &solution, int numOfCoins, int coinVal)
{
	if (coinVal == 0) //base case
	{
		return 0;
	}
	int result = INT_MAX - 1;                  //don't want a possible overflow
	for (int i = 0; i < numOfCoins; i++)
	{
		if (nums[i] <= coinVal)
		{
			int subResult = changeslow(nums, solution, numOfCoins, coinVal - nums[i]);
		
			if ((subResult != INT_MAX - 1) && (subResult + 1 < result))
			{
				result = subResult + 1;
				solution[i]=result;
			}
		}
		else if (solution[i] > 0) { solution[i]--; }
	}
	return result;
}

vector <int> changegreedy(vector<int> &nums, int numOfCoins, int targetChange) {

	vector<int> solution(numOfCoins);
	fill(solution.begin(), solution.end(), 0);
	int minCoins = 0;
	int currentChange = 0;

	for (int i = numOfCoins - 1; i >= 0; i--) {
		int temp = (targetChange - currentChange) / nums[i];
		if (temp >= 1) {
			solution[i] += temp;
			currentChange += nums[i] * temp;
			if (currentChange == targetChange) { break; }
			minCoins += temp;
		}

	}
	solution.push_back(minCoins);
	return solution;
}

void vectorOutput(vector<float> &input, int inputSize, ofstream * outputFile)
{
	*outputFile << "[";
	for (int i = 0; i <inputSize; i++) {


		*outputFile << input[i];

		if (i != (inputSize - 1))
			*outputFile << ", ";
	}

	*outputFile << "]" << endl;
}

void vectorOutput(vector<int> &input, int inputSize, ofstream * outputFile)
{
	for (int i = 0; i <inputSize; i++) {


		*outputFile << input[i];

		if (i != (inputSize - 1))
			*outputFile << ", ";
	}
	*outputFile << endl;
}
