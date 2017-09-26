/* CS261- Assignment 1 - Q.5*/
/* Name: Riley Brandau
 * Date: 10/2/16
 * Solution description: Takes a user input word and alters it's case.
 *                       Example: Random -> RaNdOm
 */
//#pragma warning (disable : 4996)
 
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
	//looking at first character in word. If it is lowercase, capitalize it.
	if (word[i] > 96 && word[i] < 123)
	{
		word[i] = toUpperCase(word[i]);
	}
	i++;
	//loop checks prior character to determine if case should change
	while (word[i] != 0)
	{
		if (word[i - 1] > 40 && word[i - 1] < 91) //preceeding letter is Uppercase
		{
			if (word[i] > 40 && word[i] < 91)
			{
				word[i] = toLowerCase(word[i]);
			}
		}
		if (word[i - 1] > 96 && word[i - 1] < 123) //preceeding letter is lowercase
		{
			if (word[i] > 96 && word[i] < 123)
			{
				word[i] = toUpperCase(word[i]);
			}
		}
		i++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char str[32] = { 0 };
	printf("Please enter a word: ");
	scanf("%s", str);

	//printf("%s\n", str);
    /*Call sticky*/
	sticky(str);
    /*Print the new word*/
	printf("%s\n", str);
    
    return 0;
}
