/* CS261- Assignment 1 - Q.2*/
/* Name: Riley Brandau
 * Date: 10/2/16
 * Solution description: Takes three variables and alters their values by passing
                         them through foo(). Prints before and after.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    
    /*Set b to half its original value*/
	*b = *b / 2;
    /*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;
	
	/*Print the values of x, y and z*/
	printf("x = %d\ny = %d\nz = %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
	z = foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("Result of foo() = %d\n", z);
    /*Print the values of x, y and z again*/
	printf("x = %d\ny = %d\nz = %d\n", x, y, z);
 
    /*Is the return value different than the value of z?  Why?*/
	/*No, since we are passing the addresses of the variables, it is
	  altering the variable's value instead of a copy of its value.
	  if a copy of the values were used, I would expect z to still be
	  changed, since it is being assigned a new value as a result of foo(),
	  but x and y would remain 5 and 6, respectively.*/
    return 0;
}
    
    
