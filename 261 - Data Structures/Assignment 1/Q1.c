/* CS261- Assignment 1 - Q.1*/
/* Name: Riley Brandau
 * Date: 9/25/16
 * Solution description: uses a Knuth shuffle to randomize student IDs
 *                       prints out student IDs and scores as well as
 *                       minimum, maximum, and average scores
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	int x = 10;
	struct student *studArr;
	studArr = (struct student*) calloc(x,sizeof(struct student));  //allocating space for array
	if (studArr == NULL)
	{
		printf("Unable to allocate memory.");
		exit(1);
	}
     /*return the pointer*/
	return studArr;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	
	int x = 10;
	//assigning IDs to array
	for (int i = 1; i < 11; i++)
	{
		students[i-1].id = i;
	}
	//shuffling IDs randomly
	for (int i = x - 1; i > 0; --i)
	{
		int y = rand() % i;
		int z = students[i].id;
		students[i].id = students[y].id;
		students[y].id = z;
	}
	//assigning random scores
	for (int i = 0; i < 10; i++)
	{
		students[i].score = rand() % 101;
	}
	
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("ID%d Score%d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = 100;
	int max = 0;
	int avg = 0;
	for (int i = 0; i < 10; i++)
	{
		if (students[i].score > max)
		{
			max = students[i].score;
		}
		if (students[i].score < min)
		{
			min = students[i].score;
		}
		avg += students[i].score;
	}
	avg = avg / 10;
	printf("Minimum score: %d\nMaximum score: %d\nAverage score: %d\n", min, max, avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud); //not sure why program hangs/crashes here.
	            //allocate() returns a pointer that is assigned to stud
	            // stud is not assigned anything else, but calling free()
	            // on it causes a crash
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	//deallocate(stud);  //calling this function causes a crash for some reason.
	
    return 0;
}
