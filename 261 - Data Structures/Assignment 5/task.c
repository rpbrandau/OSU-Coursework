/*
 * CS 261 Assignment 5
 * Name: Riley Brandau
 * Date: 11/13/16
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	struct Task *n_Task = malloc(sizeof(struct Task));
	strcpy(n_Task->name, name);
	n_Task->priority = priority;
    return n_Task;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{

	Task* l_task = left;
	Task* r_task = right;

    // FIXME: implement
	if (l_task->priority < r_task->priority)
	{
		return -1;
	}
	else if (l_task->priority > r_task->priority)
	{
		return 1;
	}
	else
	{
   		return 0;
	}
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
