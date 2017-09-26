/*
 * CS 261 Assignment 5
 * Name: Riley Brandau
 * Date: 11/13/16
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#define FORMAT_LENGTH 256  //defined the constant here because I was getting an error in VS
/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
	const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
	TYPE newTask;
	TYPE firstTask;
	char filename[50], description[100];
	char *n_ptr;
	FILE *file_ptr;
	int priority;

	switch (command)
	{
		//load to-do list from a file
		case 'l':
		//prompt user for filename
			printf("Please enter the filename: ");
			if (fgets(filename, sizeof(filename), stdin) != NULL)
			{
				n_ptr = strchr(filename, '\n');
				if (n_ptr)
				{
					*n_ptr = '\0';
				}
			}
			//open file
			file_ptr = fopen(filename, "r");
			//throw error if file is not found
			if (file_ptr == NULL)
			{
				fprintf(stderr, "Can't open file: %s\n", filename);
				break;
			}
			//load the list from the file
			listLoad(list, file_ptr);
			//close file
			fclose(file_ptr);
			//display operation confirmation
			printf("Loaded list from file successful.\n\n");
			break;

		//save list to a file
		case 's':
			if (dySize(list) > 0)
			{
				printf("Please enter the filename: ");
				if (fgets(filename, sizeof(filename), stdin) != NULL)
				{
					//removing newline character from end
					n_ptr = strchr(filename, '\n');
					if (n_ptr)
					{
						*n_ptr = '\0';
					}
				}
				//opening file
				file_ptr = fopen(filename, "w");
				if (file_ptr == NULL)
				{
					fprintf(stderr, "Can't open file: %s\n", filename);
					break;
				}
				//saving list to file
				listSave(list, file_ptr);
				//closing file
				fclose(file_ptr);
				//displaying operation confirmation
				printf("List saved to %s\n");
			}
			else
			{
				printf("No items in to-do list to save...\n");
			}
			break; 
		
		//add a new task
		case 'a':
			//get description from user
			printf("Please enter a short description of your task: ");
			if (fgets(description, sizeof(description), stdin) != NULL)
			{
				n_ptr = strchr(description, '\n');
				if (n_ptr)
				{
					*n_ptr = '\0';
				}
			}
			//user assigns a value to priority
			do
			{
				printf("Please enter a priority level for the task in the range of [0-99]: ");
				scanf("%d", &priority);
			} while (!(priority >= 0 && priority <= 99));

			while (getchar() != '\n');

			newTask = taskNew(priority, description);
			dyAdd(list, newTask);
			printf("%s has been added to your to-do list.\n", description);
			break;
		
		//get first task
		case 'g':
			if (dySize(list) > 0)
			{
				firstTask = dyHeapGetMin(list);
				Task first = *(Task*)firstTask;
				printf("Your first task is: %s\n", first.name);
			}
			else
			{
				printf("Your to-do list is empty.\n");
			}
			break;

		//remove first task
		case 'r':
			if (dySize(list) > 0)
			{
				firstTask = dyHeapGetMin(list);
				Task first = *(Task*)firstTask;
				dyRemoveAt(list, 0);
				printf("%s has been removed from the list. \n", first.name);
			}
			else
			{
				printf("Nothing to remove. List is empty.\n");
			}
			break;

		//print to-do list
		case 'p':
			if (dySize(list) > 0)
			{
				listPrint(list);
			}
			else
			{
				printf("List is empty.\n");
			}
			break;

		//exit program
		case 'e':
			printf("Sayonara! (Bye!)\n");
			break;

		default:
			printf("Please enter a valid command: \n");
			break;

	}
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}