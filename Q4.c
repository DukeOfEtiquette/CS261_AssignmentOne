/* CS261- Assignment 1 - Q.4*/
/* Name: Adam DuQuette
 * Date: June 29, 2015
 * Solution description:
 *
 * 		This solution will generate a number of students then sort them in
 * 		ascending order based on their score value.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     

	int i, j, temp;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - i; j++)
		{
			if(students[j].score > students[j+1].score)
			{
				temp = students[j+1].score;
				students[j+1].score = students[j].score;
				students[j].score = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/

	int n = 10;
    
    /*Allocate memory for n students using malloc.*/

	struct student *stud = malloc(sizeof(struct student) * n);
    
    /*Generate random IDs and scores for the n students, using rand().*/

	int i, j, testID;
	srand(time(NULL));

	for(i = 0; i < n; i++)
	{
		stud[i].score = rand()%100 + 1;

		LOOP:testID = rand()%n + 1;

		for(j = 0; j < i; j++)
		{
			if(testID == stud[j].id)
			{
				goto LOOP;
			}
		}

		stud[i].id = testID;
	}
    
    /*Print the contents of the array of n students.*/

	printf("### Unsorted ###\n");

	for(i = 0; i < n; i++)
	{
		printf("ID%i Score%i \n", stud[i].id, stud[i].score);
	}

    /*Pass this array along with n to the sort() function*/

	sort(stud, n);
    
    /*Print the contents of the array of n students.*/
    
	printf("### Sorted ###\n");

	for(i = 0; i < n; i++)
	{
		printf("ID%i Score%i \n", stud[i].id, stud[i].score);
	}

    return 0;
}
