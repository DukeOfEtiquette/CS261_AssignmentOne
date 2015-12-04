/* CS261- Assignment 1 - Q.3*/
/* Name: Adam DuQuette
 * Date: June 29, 2015
 * Solution description:
 *
 * 		This solution will create a dynamic array of integers and eventually
 * 		sort them in ascending order.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/     

	int i, j, temp;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - i; j++)
		{
			if(number[j] > number[j+1])
			{
				temp = number[j+1];
				number[j+1] = number[j];
				number[j] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/

	int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/

	int *arr;
	arr = (int*)malloc(sizeof(int) * n);
    
    /*Fill this array with random numbers, using rand().*/

	srand(time(NULL));

	for(int i = 0; i < 20; i++)
	{
		arr[i] = (rand()%42) + 1;
	}
    
    /*Print the contents of the array.*/

	printf("### Unsorted ###\n");

	for(int i = 0; i < 20; i++)
	{
		printf("Element %i: %i \n", i, arr[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/

	sort(arr, n);

    /*Print the contents of the array.*/    

	printf("### Sorted ###\n");
    
	for(int i = 0; i < 20; i++)
	{
		printf("Element %i: %i \n", i, arr[i]);
	}

    return 0;
}
