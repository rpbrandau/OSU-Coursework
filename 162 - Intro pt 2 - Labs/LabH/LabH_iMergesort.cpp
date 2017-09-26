//Source: http://stackoverflow.com/questions/22866585/c-implementation-of-iterative-merge-sort-crashing-at-large-input-sizes-due-to
//Notes: this program was not very intuitive for me to use. Especially with defining a global variable, and using namespace std


//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

int L[100000];
int R[100000];

using namespace std;
int min(int a, int b);
void Merge(int data[], int p, int q, int r);
void MergeSort(int data[], int p, int r);
bool IsSorted(int data[], int size);

int main()
{
	int data[SIZE];
	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = rand() % 10000;
		}

		int iStart, iStop, iTotal;

		iStart = clock();
		MergeSort(data, 0, SIZE - 1);
		iStop = clock();

		iTotal = (iStop - iStart) / double(CLOCKS_PER_SEC) * 1000;
		if (IsSorted(data, SIZE))
			cout << "Sorted correctly" << endl;
		else
			cout << "incorrect sorting" << endl;

		cout << "Time to run " << iTotal << endl;
	}
	return 0;

}

bool IsSorted(int data[], int size)
{
	int i;

	for (i = 0; i<(size - 1); i++)
	{
		if (data[i] > data[i + 1])
			return false;
	}
	return true;
}

void MergeSort(int data[], int p, int r)
{
	for (int i = 1; i< SIZE; i *= 2)
		for (int j = 0; j < SIZE; j += 2 * i)
			Merge(data, j, j + i - 1, min((j + 2 * i - 1), SIZE - 1));
}

void Merge(int data[], int p, int q, int r)
{
	if (q >= SIZE)q = (r + p) / 2;
	int sizeL = q - p + 2;
	int sizeR = r - q + 1;

	for (int i = 0; i < sizeL - 1; i++)
		L[i] = data[i + p];
	for (int i = 0; i < sizeR - 1; i++)
		R[i] = data[i + q + 1];

	int max;
	if (L[sizeL - 2]>R[sizeR - 2])
		max = L[sizeL - 2] + 1;
	else
		max = R[sizeR - 2] + 1;
	L[sizeL - 1] = R[sizeR - 1] = max;

	int indexL = 0, indexR = 0;
	for (int i = p; i <= r; i++) {
		if (L[indexL] <= R[indexR]) {
			data[i] = L[indexL];
			indexL++;
		}
		else {
			data[i] = R[indexR];
			indexR++;
		}
	}


}

int min(int a, int b) {
	return !(b<a) ? a : b;
}
