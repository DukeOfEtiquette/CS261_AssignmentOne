/* CS261- Assignment 1 - Q.5*/
/* Name: Adam DuQuette
 * Date: June 29, 2015
 * Solution description:
 *
 * 		This solution will read a word from the keyboard and apply sticky caps
 * 		to it.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int i = 0;

	while((int)word[i] != 0)
	{
		if( (i%2 == 0) && islower(word[i]) )
		{
			word[i] = toUpperCase(word[i]);
			i++;
		}else{

			i++;
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char word[256];

	printf("Enter a word: ");
	scanf("%s", word);

    /*Call sticky*/

	sticky(&word[0]);
    
    /*Print the new word*/

	printf("New word: %s \n", word);
    
    return 0;
}
