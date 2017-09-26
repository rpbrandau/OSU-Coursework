/* CS261- Assignment 1 - Q.3*/
/* Name: Riley Brandau
 * Date: 10/2/16
 * Solution description: fills an array with random numbers (0 to 1000). Prints array.
                         Passes array through sort(). Prints sorted array.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (number[i] > number[j])
			{
				int x = number[i];
				number[i] = number[j];
				number[j] = x;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int *intArr = (int *)malloc(sizeof(n));
    
    /*Fill this array with random numbers, using rand().*/
	for (int i = 0; i < n; i++)
	{
		intArr[i] = rand() % 1000;
	}
    
    /*Print the contents of the array.*/
	for (int i = 0; i < n; i++)
	{
		printf("Array position %d = %d\n", i+1, intArr[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(intArr, n);

    /*Print the contents of the array.*/    
	for (int i = 0; i < n; i++)
	{
		printf("Sorted: Array position %d = %d\n", i + 1, intArr[i]);
	}
    return 0;
}
