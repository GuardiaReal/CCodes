
/*file: wordCount.c
 *author: Tristan Caputo
 *purpose: Takes in a text from stdin an prints out its frequency count of all the words, listing the words in alphabetical order. 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/********************************************************************************
 *										*
 *										*
 *				GLOBALS						*
 *										*
 *******************************************************************************/
int a = 0;


/*this method looks at our dynamically allocated string array and counts the frequency 
 *(of the word passed to it) by going through the string with a for loop and using
 *strcmp().
 */

int findCount(char **words, char *wd)
{
    int count = 0;

    for (int i = 0; i < a; i++) {
//      if (*words == NULL)
//              break;
	if (strcmp(wd, words[i]) == 0)
	    count++;
    }
    return count;

}


int main(void)
{
    int error = 0;
    char **words = malloc(sizeof(char *) * 1024);
    int i = 0;
    char *word = malloc(sizeof(char) * 129);
    char *tmp;

    while (scanf("%s", word) != EOF) {
	i = 0;

	while (word[i]) {
	    word[i] = tolower(word[i]);	//converts words to lowercase

	    if (!isalpha(word[i])) {	//strips non-alpha characters
		word[i] = '\0';
		if (word[i + 1] == '\0')
		    break;
		words[a] = malloc(sizeof(char) * 129);
		words[a] = strdup(word);
		a++;
		word = word + strlen(word) + 1;
		i = 0;
		continue;
	    }

	    i++;
	}

	words[a] = malloc(sizeof(char) * 129);	//inserting word value in char pointer array
	words[a] = strdup(word);
	a++;
    }



    for (int j = 0; j < a; j++)
	for (int k = j + 1; k < a; k++) {
	    if (strcmp(words[j], words[k]) > 0) {
		tmp = words[j];
		words[j] = words[k];
		words[k] = tmp;
	    }
	}
    char *wd = "\0";

    for (int i = 0; i < a; i++) {
	if (strcmp(wd, words[i]) != 0)
	    printf("%s %d\n", words[i], findCount(words, words[i]));
	wd = words[i];
    }


    return error;
}
