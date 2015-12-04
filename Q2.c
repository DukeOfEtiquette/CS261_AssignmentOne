/* CS261- Assignment 1 - Q.2*/
/* Name: Adam DuQuette
 * Date: June 29, 2015
 * Solution description:
 *
 * 		This solution will simply create 3 int variables, manipulate the value
 * 		of two of them in a function, and leave the third alone.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;
    /*Set b to half its original value*/
	*b /= 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
   
	int x = 5, y = 6, z = 7;
 
    /*Print the values of x, y and z*/

	printf("X: %i, Y: %i, Z: %i \n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/

	int retVal = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
   
	printf("foo returned: %i \n", retVal);
 
    /*Print the values of x, y and z again*/

	printf("X: %i, Y: %i, Z: %i \n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/

	//The returned value and z are different because when z is passed to foo
	//a copy of it's value is made as a local varible in the function.
	//Therefore, the variable z is untouched while foo is exectured. The same
	//cannot be said for x and y since the addres for those variables is 
	//passed and therefore the actual values of x and y and manipulated.
    return 0;
}
    
    
