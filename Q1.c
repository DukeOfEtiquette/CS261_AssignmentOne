/* CS261- Assignment 1 - Q.1*/
/* Name: Adam DuQuette
 * Date: June 29, 2015
 * Solution description:
 *
 * 		This solution makes use of a student struct and demonstrates it's
 * 		functionality. A student is defined to have a unique ID and a score.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *x = malloc(sizeof(struct student)*10);
     /*return the pointer*/
	 return x;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int i, j, testID;
	srand(time(NULL));

	for(i = 0; i < 10; i++)
	{
		//Generate random score value 1 - 100 inclusive
		students[i].score = rand()%100 + 1;

		//Get a possible unique student id
		LOOP:testID = rand()%10 + 1;

		//This loop will iterate once for every student that already has an ID
		//It will check to see if our testID is already being used, if so then
		//it will jump above this and generate a new id to test, otherwise
		//it will fall out of this loop and assign the id to the current
		//student
		for(j = 0; j < i; j++)
		{
			if(testID == students[j].id)
			{
				goto LOOP;
			}
		}

		students[i].id = testID;
	} 
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("ID%i Score%i \n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int i, min = students[0].score, max = students[0].score;
	double avg = 0;

	for(i = 0; i < 10; i++)
	{
		if(students[i].score < min)
			min = students[i].score;

		if(students[i].score > max)
			max = students[i].score;

		avg += students[i].score;
	}

	//Divide sum of all score by number of students
	avg /= 10;

	printf("Minimum score: %i \nMaximum score: %i \nAverage score: %f \n", min, max, avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if(stud != NULL)
		free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
