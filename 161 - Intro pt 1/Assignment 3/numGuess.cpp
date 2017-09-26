/**********
 * Author: Riley Brandau
 * Date: 1/20/16
 * Description: Assignment 3.c - This is a guessing game program. The user will enter an integer for the player to guess. If the player's guess is higher than the target number, it will display "too high." And if the guess is lower than the target number, it will display "too low." Once the correct integer is guessed, the program will say how many guesses it took.
**********/

#include <iostream>

using namespace std;

int main()
{
	int userNum,
	    guessNum,
	    counter = 1;

//get an integer from the user
	cout << "Please enter an integer for the player to guess." << endl;
	cin >> userNum;

//get the first guess
	cout << "Please enter your guess." << endl;
	cin >> guessNum;

//loop to compare guessNum and userNum
	do
	{
		if(guessNum < userNum)
		{
			counter++;
			cout << "Too low. Try again!" << endl;
			cin >> guessNum;
		}
		else if(guessNum > userNum)
		{
			counter++;
			cout << "Too high. Try again!" << endl;
			cin >> guessNum;
		}
	}
	while (guessNum != userNum);

	cout << "You guessed it in " << counter << " tries!" << endl;
return 0;
}
