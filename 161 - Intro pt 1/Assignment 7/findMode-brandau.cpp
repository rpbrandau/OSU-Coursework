/*****
 * Author: Riley Brandau
 * Date: 2/16/16
 * Description: This file contains a function falled findMode, which will take an array of integers and return its mode(s) in a vector.
*****/

#include <iostream>
#include <vector> //needed for using vectors
#include <algorithm> //needed for using sort()
using namespace std;

/***
 * function for printing out vectors in main

void printVector(vector<int> vect, int size)
{
   for(int i = 0; i < size; i++)
   {
      cout << vect[i] << " ";
   }
}
***/


vector<int> findMode(int array[], int size)//function takes an array and an int
{
   vector<int> vect(array, array + size); //copying the array to a vector
   vector<int> mode;
   int freq = 1;
   int max = 1;

   sort(vect.begin(), vect.end()); //sorting the vector before running mode tests

   for(int pass = 0; pass != vect.size(); pass++)
   {
      if(pass == 0)
      {
         mode.push_back(vect[pass]);
         continue; //skipping rest of code w/o resetting counter
      }
      if(vect[pass] == vect[pass - 1]) //comparing vector subscript for equality
      {
         freq++; //increasing frequency when 2 or more numbers are found to be the same
	 if(freq > max)
	 {
	    max = freq; 
	    mode.clear(); //clears vector of data
	    mode.push_back(vect[pass]); //adding a mode element to the vector
	 }
	 else if(freq == max) //adding a mode when frequency and max are the same
	 {
	    mode.push_back(vect[pass]);
	 }
       }
       else if(max < 2) //for when there are no duplicate numbers
       {
	 mode.push_back(vect[pass]);
       }
       else
       {
	 freq = 1; //resetting the counter to 1 if no modes are found
       }
  }

  sort(mode.begin(), mode.end()); //sorting the modes to be in ascending order
  return mode;
}

 
/***
 * main method for testing
 
int main()
{
const int ARRAYA_SIZE = 7;
const int ARRAYB_SIZE = 9;
const int ARRAYC_SIZE = 1;

int arrayTestA[] = {3,2,4,2,6,6,5};
int arrayTestB[] = {2,5,5,5,6,2,8,1,1};
int arrayTestC[] = {0};

vector<int> vectA = findMode(arrayTestA, ARRAYA_SIZE);
vector<int> vectB = findMode(arrayTestB, ARRAYB_SIZE);
vector<int> vectC = findMode(arrayTestC, ARRAYC_SIZE);

printVector(vectA, vectA.size());
printVector(vectB, vectB.size());
printVector(vectC, vectC.size());


return 0;
}
***/
