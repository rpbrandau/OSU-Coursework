/* CS261- Assignment 1 - Q. 0*/
/* Name: Riley Brandau
 * Date: 9/25/16
 * Solution description: displays the value and address of both a variable and a pointer to that variable.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("the value pointed to by iptr* is: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
	printf("The address pointed to by iptr* is: %p\n", iptr);
     /*Print the address of iptr itself*/
	printf("The address of iptr itself is: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 10;
    
    /*print the address of x*/
	printf("Printing the address of x: %p\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("The value of x: %d\n", x);
    
    return 0;
}
