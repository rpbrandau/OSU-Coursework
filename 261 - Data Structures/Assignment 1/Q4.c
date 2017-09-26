/* CS261- Assignment 1 - Q.4*/
/* Name: Riley Brandau
 * Date: 10/2/16
 * Solution description: Creates an array of students that have ids and scores.
                         Randomly assigns ids and scores, then prints the array.
						 Sorts the array based on the student's score.
						 Prints the sorted array.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/    
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (students[i].score > students[j].score)
			{
				//swapping scores
				int temp_s = students[i].score;
				students[i].score = students[j].score;
				students[j].score = temp_s;
				//swapping IDs to ensure they stick with their score
				int temp_i = students[i].id;
				students[i].id = students[j].id;
				students[j].id = temp_i;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;
    
    /*Allocate memory for n students using malloc.*/
	struct student* studArray = (struct student *) malloc(n*sizeof(struct student));
	if (studArray == NULL)
	{
		printf("Unable to allocate memory. Exiting Program.");
		exit(1);
	}
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	for (int i = 1; i < n + 1; i++)
	{
		studArray[i-1].id = i;
	}
	for (int i = n - 1; i > 0; --i)
	{
		int y = rand() % i;
		int z = studArray[i].id;
		studArray[i].id = studArray[y].id;
		studArray[y].id = z;
	}
	for (int i = 0; i < n; i++)
	{
		studArray[i].score = rand() % 101;
	}
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < n; i++)
	{
		printf("ID %d Score %d\n", studArray[i].id, studArray[i].score);
	}

    /*Pass this array along with n to the sort() function*/
	sort(studArray, n);
    
    /*Print the contents of the array of n students.*/
	printf("\nSorted by score:\n");
	for (int i = 0; i < n; i++)
	{
		printf("ID %d Score %d\n", studArray[i].id, studArray[i].score);
	}

    return 0;
}
