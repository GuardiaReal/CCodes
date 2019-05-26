/*file: mayan.c
 *author: Tristan Caputo
 *purpose: takes in as many mayan (base-20) numbers and returns their decimal values
 */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
int scanner, i;
int error=0;
char word[6+1];
while ((scanner=scanf("%s",  word)) != EOF)
{i=0;
       while (word[i])
	{
	if (isdigit(word[i]))
		{error = 1;
		 fprintf(stderr, "ERROR: Not valid base-20 format..");
		 i++;}
	if (word[i] == 'u' || word[i]=='v' || word[i]=='w' || word[i]=='x' || word[i]=='y' ||word[i]=='z')
		{error = 1;
		 fprintf(stderr, "ERROR: Not a valid base-20 format..");
		 i++;}

		
	/*
	 *CODE HERE !
	 */
		

	i++;
	}

}

if (error==1)
	return 1;
return 0;



}
