
/*file: spellcheck.c
 *author: Tristan Caputo
 *purpose: acts as a spellchecker using a dictionary file as a reference
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*******************************************************************
*								   *
*								   *
*			GLOBAL VARIABLES			   *
*								   *
********************************************************************/

FILE *dicPtr;
FILE *inpPtr;
char **wordsUsed;
int uniqueSetting;
int a=0;

char *stripWd(char *wd);
void findWordsInDic(char *word, char *dicName);
void traversingInputFile(char *inpName, char *dicName);
void readScanner(char *dicName);
int main(int argc, char *argv[])
{
      uniqueSetting = 0;
    int openScanner = 1;
    int dicFound = 0;
    int inpFound = 0;
    char *dicName = NULL;
    char *inpName = NULL;
//    wordsUsed = malloc(sizeof(char*)*512);

    for (int i = 1; i < argc; i++) {
	// IF -u or -i or -d is encountered do something !

	if (strcmp(argv[i], "-u") == 0){
	    uniqueSetting = 1;
	    wordsUsed = malloc(sizeof(char)*512);}

	if (strcmp(argv[i], "-d") == 0) {
	    if (dicFound != 1)
		dicName = argv[i + 1];
	    dicFound = 1;
	}


	if (strcmp(argv[i], "-i") == 0) {
	    if (inpFound != 1)
		inpName = argv[i + 1];
	    inpFound = 1;
	    openScanner = 0;
	}
	/*else {
	   fprintf(stderr, "ERROR: Unrecognized arguments passed !\n");
	   exit(1);} */
    }

/**********************************************************************************
*										  *
*										  *
*				ERROR HANDLING CASES				  *
*										  *
*										  *
**********************************************************************************/



    if (dicName != NULL)
	if (dicName[0] == '-') {
	    fprintf(stderr,
		    "ERROR: Cannot have dictionary file start with '-'\n");
	    exit(1);
	}
    if (argc > 6) {
	fprintf(stderr, "ERROR: Too many arguments supplied !\n");
	exit(1);
    }

    if (dicName == NULL) {
	fprintf(stderr,
		"ERROR: dictionary name has not been passed as argument !\n");
	exit(1);
    }
    if (inpName != NULL)
	if (inpName[0] == '-') {
	    fprintf(stderr,
		    "ERROR: Cannot have input file start with '-'\n");
	    exit(1);
	}
    if (!openScanner && inpName == NULL) {
	fprintf(stderr, "ERROR: -i passed without name of input file\n");
	exit(1);

    }

    if (openScanner)
	readScanner(dicName);
    if (!openScanner)
	traversingInputFile(inpName, dicName);
    return 0;
}

/*check if word that wasn't found in the dictionary file was already inputed*/

int wordAlreadyUsed(char *wd)
{
 int found = 0;
 
 for (int i=0; i<a; i++){
	if (wordsUsed == NULL)
		break;
	if (strcmp(wd, wordsUsed[i])==0)
		found = 1;}
 if (found==0){
	wordsUsed[a] = malloc(sizeof(char*)+64);
	wordsUsed[a] = strdup(wd);
	++a;
 	      }
 return found;
}

/*
 *this method takes in a char pointer of the word the user is looking up in the dictionary
 *and it also takes in a char pointer to the name of the dictionary file. the program 
 *gives back a void output but prints out the word we're looking for if it cannot be found *within the dictionary.
 */

void findWordsInDic(char *word, char *dicName)
{
    char *line = malloc(sizeof(char));
    size_t size = 1;
    int i;
   // a=0;
    int found = 0;
    dicPtr = fopen(dicName, "r");
  //  wordsUsed = malloc(sizeof(char*)*512);

    if (dicPtr) {
	while (getline(&line, &size, dicPtr) > 0) {

	    i = 0;
	    while (line[i]) {
		line[i] = tolower(line[i]);
		if (!isalpha(line[i])) {
		    line[i] = '\0';
		    if (line[i + 1] == '\0')
			break;
		    if (strcmp(word, line) == 0)
			found = 1;
		    line = line + strlen(line) + 1;
		    i = 0;
		    continue;
		}
		i++;
	    }
	    if (strcmp(word, line) == 0)
		found = 1;
	}

	if (found==0 && uniqueSetting==1)
		if (wordAlreadyUsed(word) == 0)
			printf("%s\n", word);

	if (found == 0 && uniqueSetting ==0)
	    printf("%s\n", word);
//              close(dicPtr);
   }

    else {
	perror("ERROR");
	exit(1);
    }
    return;
}

/*
 *this method traverses the input file word by word dismissing non-alphabetical characters *as it traverses the list it searches for each word in the dictionary by calling
 *"findWordsInDic(char *word, char* dicName).
 */
void traversingInputFile(char *inpName, char *dicName)
{
    char *line = malloc(sizeof(char));
    size_t size = 1;
    int i;
    inpPtr = fopen(inpName, "r");

    if (inpPtr) {
	while (getline(&line, &size, inpPtr) > 0) {

	    i = 0;
	    while (line[i]) {
		line[i] = tolower(line[i]);
		if (!isalpha(line[i])) {
		    line[i] = '\0';
		    if (line[i + 1] == '\0')
			break;
		    findWordsInDic(strdup(line), dicName);
		    line = line + strlen(line) + 1;
		    i = 0;
		    continue;
		}
		i++;
	    }
	    findWordsInDic(strdup(line), dicName);
//	close(inpPtr);
	}
    } else {
	perror("ERROR");
	exit(1);
    }

    return;
}

/*If no input file is inputed in the program, main() will automatically call this 
 *method which opens a stdin scanner to read in the user's words one by one dismissing
 *any non-alphabetical characters.
 */

void readScanner(char *dicName)
{
    char *wd = (char *) malloc(sizeof(char));
    int i;

    while (scanf("%s", wd) > 0) {
	i = 0;
	while (wd[i]) {
	    wd[i] = tolower(wd[i]);
	    if (!isalpha(wd[i])) {
		wd[i] = '\0';
		if (wd[i + 1] == '\0')
		    break;
		findWordsInDic(strdup(wd), dicName);
		wd = wd + strlen(wd) + 1;
		i = 0;
		continue;
	    }
	    i++;
	}
	findWordsInDic(strdup(wd), dicName);
    }



    return;
}
