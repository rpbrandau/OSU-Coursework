/*
 * Riley Brandau
 * CS 344 - Project 4 - keygen.c
 * Due 3/19/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <limits.h>

const char BYTES[] = "%s number\n\tnumber is the key size in bytes\n";                   //for displaying key size in bytes

int main(int argc, char** argv) 
{
    srand(time(NULL));                                                                   //seed random number generator
    int val = -5;
    long key_size = -5;
    long i = -5;

    if (argc != 2)                                                                       //incorrect number of arguments passed
    {
        fprintf(stderr, BYTES, argv[0]);
        exit(EXIT_FAILURE);
    }
	
    key_size = strtol(argv[1], NULL, 10);                                                //convert the passed number ito a long number

    if (errno == ERANGE)                                                                 //the passed number was not in the correct range
    {
        fprintf(stderr, "Input %s is too large/small. It must be between %ld and %ld.\n", argv[0], LONG_MIN, LONG_MAX);
        exit(ERANGE);
    }

    if (errno == EINVAL)                                                                 //the passed number was invalid
    {
        fprintf(stderr, "INVALID INPUT: %s\n", argv[1]);
        exit(EINVAL);
    }

    for (i = 0; i < key_size; i++)                                                       //print the key
    {
        val = rand() % 27;
		
        if (val == 26) 
	{
            val = ' ';
        } 
	else 
	{
            val += 'A';
        }
        printf("%c", (char)val);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
