/*file: palindromes.c
 *author: Tristan Caputo
 *purpose: takes in a stream of words and prints 1 if the word is a palindrome and 0 if if it isn't
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char word[], int len)
{
if (len <= 0)
	return 1;
if (word[0] == word[len-1])
	return isPalindrome(word+1, len-2); 

return 0;
}

int main (void)
{
char word[65]; //64 char + '\0' = 65bits
int scanner, i, len;

while ((scanner=scanf("%s", word))!=EOF)
{i=0;
	while (word[i])
	{
	word[i] = tolower(word[i]);
	i++;
	}
	len = strlen(word);
	printf("%d\n", isPalindrome(word, len));

}
return 0;

}
