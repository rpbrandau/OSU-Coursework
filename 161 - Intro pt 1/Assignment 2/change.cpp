/**********
 * Author: Riley Brandau
 * Date: 1/12/16
 * Description: Project 2.c - A program that asks the user for a number of cents between 0 and 99, and outputs how many
 * or each type of coin would represent that amount with the fewest total number of coins.
 **********/

#include <iostream>

using namespace std;

int main()
{
   int cents, quarters, dimes, nickels, pennies; //defining variables

   cout << "Please enter an amount, in cents, less than a dollar: " << endl;
   cin >> cents; //storing user input in variable

/*****
 * This block of code  breaks the user's cent input into quarters, dimes, nickels, and pennies. (Albiet crudely)
 *****/

   quarters = cents/25;
   dimes = (cents - (quarters*25))/10;
   nickels = (cents - (quarters*25 + dimes*10))/5;
   pennies = (cents - (quarters*25 + dimes*10 + nickels*5));

   cout << "Your change will be: " << endl;
   cout << "Quarters: " << quarters << endl << "Dimes: " << dimes << endl;
   cout << "Nickels: " << nickels << endl << "Pennies: " << pennies << endl;

   return 0;
}
