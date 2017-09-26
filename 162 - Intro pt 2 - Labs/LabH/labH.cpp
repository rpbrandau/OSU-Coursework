// labH.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string>
#include <fstream>
#include <ostream>


void r_merge(int arr[], int low, int high, int mid);
void r_mergeSort(int arr[], int l, int r);


int main()
{
	srand(time(NULL));
	
	int n = 0;
	std::string filename;
	std::cout << "How many numbers would you like generated?" << std::endl;
	std::cin >> n;
	std::cout << "Enter a filename to save generated numbers: ";
	std::cin >> filename;
	std::ofstream output;
	output.open(filename.c_str());
	
	int *out = new int[n];
	output << "Unsorted" << std::endl;
	for (int i = 0; i < n; i++)
	{
		out[i] = rand() % 10000;
		output << out[i] << std::endl;
	}

	int rStart, rStop, rTotal;
	
	rStart = clock();
	r_mergeSort(out, 0, n - 1);
	rStop = clock();

	rTotal = (rStop - rStart) / double(CLOCKS_PER_SEC) * 1000;
	output << "Sorted" << std::endl;
	for (int i = 0; i < n; i++)
	{
		output << out[i] << std::endl;
	}

	std::cout << "Time to run recursive function on "<<n<<" ints: " << rTotal << std::endl;
	output << "Time to run recursive function on " << n << " ints: " << rTotal << std::endl;
	output.close();
	return 0;
}

//Recursive merge sort functions
//Source: http://www.geeksforgeeks.org/iterative-merge-sort/
void r_mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; //Same as (l+r)/2 but avoids overflow for large l & h
		r_mergeSort(arr, l, m);
		r_mergeSort(arr, m + 1, r);
		r_merge(arr, l, m, r);
	}
}


void r_merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

