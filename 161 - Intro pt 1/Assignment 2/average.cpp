/**********
 * Author: Riley Brandau
 * Date: 1/12/16
 * Description: Project 2.a - A simple program that takes five numbers, inputted by the user, and returns their average.
 **********/

#include <iostream>

using namespace std;

int main()
{
   float num1, num2, num3, num4, num5, avgNum; //Creating float variables for user inputs

/*****
 * The following block gathers the five user inputs and assigns them to variables num1 through num5
 *****/

   cout << "Please enter five numbers, and I will give you their average!" << endl;
   cout << "Enter first number:" << endl;
   cin >> num1; 
   cout << "Enter second number:" << endl;
   cin >> num2;
   cout << "Enter third number:" << endl;
   cin >> num3;
   cout << "Enter fourth number:" << endl;
   cin >> num4;
   cout << "Enter fifth number:" << endl;
   cin >> num5;

   avgNum = (num1 + num2 + num3 + num4 + num5) /5.0; //averages the submitted numbers

   cout << "The average of the numbers you submitted is: " << avgNum << endl; //prints the average

   return 0;
}
