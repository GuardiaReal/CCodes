/*file: vowels.c
 *author: Tristan Caputo
 *purpose: takes in words through stdin and prints out 1 for each word whose vowels are in order and 0 for words whose vowels aren't in order
 */
#include <stdio.h>
#include <ctype.h>

int isInOrder(char word[])
{
char c;
int j,i=0;
int firstVowelFound=0;
int secondVowelFound=0;
	while (word [i])
	{
		c = word[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{firstVowelFound = 1;
			 break;}
	i++;
	}
 j = i+1;
	while (word [j])
	{
		c = word[j];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
			 if (c == word[i])
				{j++;
				continue;}
			 secondVowelFound = 1;
			 break;}
	j++;
	}
	
	if (firstVowelFound == 0 && secondVowelFound == 0)
		return 1;
	if (firstVowelFound == secondVowelFound)
	{
	 if (word[i] <= word [j])
		return 1;
	 else 
		return 0;
	}
		
			
return firstVowelFound; 
}

int main(void)
{
int status;
char word[65];
int i;
int bol = 0;
while ((status=scanf("%s", word))!=EOF)
{i=0;
 bol=0;
	while (word [i])
	{
	if (!isalpha(word[i]))
		{fprintf(stderr, "ERROR: Not a real word\n");
		 bol = 1;
		 break;}
	word [i] = tolower(word[i]);
 	i++;
	}
	if (bol != 1)
		printf("%d\n", isInOrder(word));
		
	
}
return bol;

} 
