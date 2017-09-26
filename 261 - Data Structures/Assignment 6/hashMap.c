/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: Riley Brandau
 * Date: Due 11/20/16
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement
	for (int i = 0; i < map->capacity; i++)
	{
		HashLink* tempLink = map->table[i];
		map->table[i] = NULL;

		while (tempLink != NULL)
		{
			HashLink* garbage = tempLink;
			tempLink = tempLink->next;
			hashLinkDelete(garbage);
		}
		free(map->table[i]);
	}
	free(map->table);
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement
	int index = 0;
	index = HASH_FUNCTION(key) % map->capacity;
	HashLink* current = map->table[index];
	
	//compare keys until correct key is found
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			return &current->value;
		}
		else
		{
			current = current->next;
		}
	}
	return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
    // FIXME: implement
	//saving old map's data
	int oldMapCap = map->capacity;
	HashLink** oldMapTable = map->table;

	//initializing new map w/ passed capacity
	hashMapInit(map, capacity);

	//putting old map's data into new map
	for (int i = 0; i < oldMapCap; i++)
	{
		HashLink* tempLink = oldMapTable[i];
		
		while (tempLink != NULL)
		{
			hashMapPut(map, tempLink->key, tempLink->value);
			tempLink = tempLink->next;
		}
	}
	//free oldMap
	for(int i = 0; i < oldMapCap; i++)
	{
		HashLink* delLink = oldMapTable[i];
		oldMapTable[i] = NULL;
		while(delLink != NULL)
		{
			HashLink* garbage = delLink;
			delLink = delLink->next;
			hashLinkDelete(garbage);
		}
		free(oldMapTable[i]);
	}
	free(oldMapTable);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
    // FIXME: implement
	int index = 0;

	//check/resize is necessary
	if (hashMapTableLoad(map) >= MAX_TABLE_LOAD)
	{
		resizeTable(map, 2 * map->capacity);
	}

	//determine index
	index = HASH_FUNCTION(key) % map->capacity;
	if (index < 0)
	{
		index += map->capacity;
	}

	//adding to buckets
	HashLink* tempLink = map->table[index];
	HashLink* newLink = NULL;
	//bucket contains no links
	if (tempLink == NULL)
	{
		newLink = hashLinkNew(key, value, NULL);
		map->table[index] = newLink;
		map->size++;
		return;
	}
	//at least one link
	else
	{
		while (tempLink != NULL)
		{
			//key exists
			if (strcmp(tempLink->key, key) == 0)
			{
				tempLink->value = value;
				return;
			}
			tempLink = tempLink->next;
		}
		newLink = hashLinkNew(key, value, map->table[index]);
		map->table[index] = newLink;
		map->size++;
		return;
	}

}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement
	int index = 0;
	index = HASH_FUNCTION(key) % map->capacity; 
	HashLink* current = map->table[index];
	HashLink* previous = map->table[index];

	//if link doesn't exist, do nothing
	if (!hashMapContainsKey(map, key))
	{
		return;
	}
	

	//no links to remove
	if (current == NULL)
	{
		return;
	}
	while (current != NULL)
	{
		//key to remove was found
		if (strcmp(current->key, key) == 0)
		{
			//link to remove happens to be first
			if (current == map->table[index])
			{
				map->table[index] = current->next;
				hashLinkDelete(current);
				map->size--;
				current = 0;
			}
			else
			{
				previous->next = current->next;
				hashLinkDelete(current);
				map->size--;
				current = 0;
			}
		}
		else
		{
			previous = current;
			current = current->next;
		}

	}
	
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement
	int index = 0;
	index = HASH_FUNCTION(key) % map->capacity;
	HashLink* current = map->table[index];

	//check map for key
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			return 1;
		}
		current = current->next;
	}
    return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement
	//make sure map is valid, then return its size
	assert(map);
	return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement
	//make sure map is valid, then return its capacity
	assert(map);
	return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement
	int emptyCount = 0;
	//count empty buckets
	for (int i = 0; i < map->capacity; i++)
	{
		if (!map->table[i])
		{
			emptyCount++;
		}
	}
    return emptyCount;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement
	//make sure map is valid
	assert(map);
	float load = 0.0;
	//calculate load
	load = (float)map->size / (float)map->capacity;
    return load;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}
