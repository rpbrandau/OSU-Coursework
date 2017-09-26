/**********
 * Author: Riley Brandau
 * Date: 1/19/16
 * Description: Assignment 3.a - This program asks the user how many integers they would like to enter, then prompts them to enter that many integers. After all integers have been entered, the program will display the largest and the smallest of those integers.
**********/

#include <iostream>

using namespace std;

int main()
{
int userInt,			//defining variable for first part of program
    enteredInt,			//defining variable for comparison
    minInt = 2147483647,	//defining variable to store minimum integer. Initialized at largest int value
    maxInt = -2147483648,	//defining variable to store maximum integer. Initialized at smallest int value
    counter = 0;                //defining variable for while loop

cout << "How many integers would you like to enter?" << endl;
cin >> userInt;

if ((userInt < 2147483647) || (userInt > -2147483648)) //testing that input is an integer
   {
        cout << "Please enter " << userInt << " integers." << endl;

	if (userInt == counter+1) //if the user only wants to input one integer
	{
	   cin >> enteredInt;
	   minInt = enteredInt;
	   maxInt = enteredInt;
        }
	else
	{
	   while (counter < userInt) //initializing a while loop for comparing entered integers
           {   
	   cin >> enteredInt; //storing user's integer for comparison
 

	     if ((userInt < 2147483647) || (userInt > -2147483648)) //testing that input is an integer
	     {
	  	 if (enteredInt < minInt) //checking if the entered integer is less than minInt
	     	 minInt = enteredInt;  //assigning minInt enteredInt's value if it is less

	   	 else if (enteredInt > maxInt) //checking if the entered integer is greater than maxint
		 maxInt = enteredInt;  //assigning maxInt enteredInt's value if it is greater

	     counter = counter + 1; //increasing loop counter only if entered value is an integer
	     }
	     else
           cout << "Please enter valid integers." << endl;
           }
	}

   }
else
cout << "Please enter a valid integer." << endl;

cout << "min:  " << minInt << endl;
cout << "max:  " << maxInt << endl;

return 0;

}

