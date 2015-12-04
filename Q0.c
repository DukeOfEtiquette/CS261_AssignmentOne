/* CS261- Assignment 1 - Q. 0*/
/* Name: Adam DuQuette
 * Date: June 29, 2015
 * Solution description:
 *
 * 		This solution will declare an int value, print it's address/value, be
 * 		passed to a function as a pointer where that will print it's address
 * 		and value and the address of the pointer itself.
 */
 
#include <stdio.h>
#include <stdlib.h>


/******************************************************************************
 * Entry: The address of an int.
 *
 * Exit: Nothing
 *
 * Purpose: This function prints the value of the int passed, the address of
 * 			the int passed, and the address of the pointer of the local
 * 			pointer variable.
 *
******************************************************************************/
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/

	 printf("Value pointed to by iptr: %i \n", *iptr);
     
     /*Print the address pointed to by iptr*/

	 printf("Address pointed to by *iptr: %p \n", &(*iptr));
     
     /*Print the address of iptr itself*/

	 printf("Address of iptr itself: %p \n", &iptr);
}

int main(){
    
    /*declare an integer x*/

	int x = 42;
    
    /*print the address of x*/

	printf("Address of x: %p \n", &x);
    
    /*Call fooA() with the address of x*/

	fooA(&x);
    
    /*print the value of x*/

	printf("Value of x: %i \n", x);
    
    return 0;
}
