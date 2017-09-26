/**********
 * Author: Riley Brandau
 * Date: 1/12/16
 * Description: Project 2.b - A program that converts a user input Celsius temperature to Fahrenheit.
 **********/

#include <iostream>

using namespace std;

int main()
{
   float celsiusTemp, fahrTemp; //defining variables

   cout << "Please enter a Celsius temperature." << endl;
   cin >> celsiusTemp; //assigning user's input to variable

   fahrTemp = (9.0/5.0)*celsiusTemp + 32.0; //converting Celsius to Fahrenheit

   cout << "The equivalent temperature in Fahrenheit is: "<< endl << fahrTemp << endl;

   return 0;
}
