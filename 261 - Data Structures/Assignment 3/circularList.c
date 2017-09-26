#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);												//list isn't null
	list->sentinel = (struct Link *)malloc(sizeof(struct Link));	//create sentinel
	assert(list->sentinel != 0);									//make sure it was successful
	list->sentinel->next = list->sentinel;							//set up sentinel pointers
	list->sentinel->prev = list->sentinel;
	list->sentinel->value = 0;
	list->size = 0;													

}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link *link = (struct Link *)malloc(sizeof(struct Link));		//create a new link
	assert(link != 0);

	link->value = value;												//assign new link's value
	return link;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	struct Link *newLink = createLink(value);							//call createLink
	assert(newLink != 0);												//assert that it worked
	assert(newLink->value != 0);

	newLink->next = link->next;											//set up newLink's pointers
	newLink->prev = link;
	link->next->prev = newLink;											//update old link's pointers
	link->next = newLink;
	list->size++;														//increase list size
	
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);
	assert(link != 0);													//make sure list and links are valid

	link->prev->next = link->next;										//update pointers
	link->next->prev = link->prev;
	free(link);															//free memory
	list->size--;														//decrease list size

}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *pos = list->sentinel->next;							//assign pointer to first element
	struct Link *nextPos = list->sentinel->next->next;					//assign pointer to second element

	for (int i = 0; i < list->size; i++)								//free memory and reduce size per link
	{
		free(pos);
		pos = nextPos;
		list->size--;
	}
	free(list->sentinel);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->next, value);				//call addLinkAfter to insert a link after the sentinel (front)
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);				//call addLinkAfter to insert a link before the sentinel (back)
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->next->value;								//sentinel->next->value = first value
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->prev->value;								//sentinel->prev->value = last value
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size > 0);

	removeLink(list, list->sentinel->next);							//removes first element
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size > 0);

	removeLink(list, list->sentinel->prev);							//removes last element

}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if (list->size == 0)											//if size = 0, the list is empty
	{
		return 1;
	}
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *pos = list->sentinel->next;						//assign a pointer to first element

	for (int i = 0; i < list->size; i++)							//loop through list (front to back)
	{
		printf("   %f", pos->value);								//display value at position
		pos = pos->next;											//update pointer to next element
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *pos = list->sentinel->prev;						//assign a pointer to the last element

	for (int i = 0; i < list->size; i++)							//loop through list (back to front)
	{
		printf("   %f", pos->value);								//display value at position
		pos = pos->prev;											//update pointer to next (well, previous) element
	}
}
