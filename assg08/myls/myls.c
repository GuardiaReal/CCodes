/*
 *file: myls.c
 *author: Tristan Caputo
 *purpose: acts as ls command
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    DIR *curDir;
    struct dirent *direntPtr;
    int len = 512;
    int i;
    char **array = malloc(len * sizeof(char *));
    char *tmp;
    char *msg;

    if (argc > 2) {
	printf("ERROR: Too Many Arguments\n");
	return 1;
    }

    if (argv[1] != NULL)
	curDir = (DIR *) opendir(argv[1]);

    if (argv[1] == NULL)
	curDir = (DIR *) opendir(".");
    i = 0;
    if (curDir != NULL)
	while (direntPtr = readdir(curDir)) {
	    msg = strdup(direntPtr->d_name);
	    array[i] = (char *) malloc(sizeof(char *) + 64);
	    array[i] = msg;
	    i++;
    } else {
	perror("ERROR");
	return 1;
    }

    closedir(curDir);

/* these nested for loops serve me to order my char pointer array according to strcmp() 
 *as well as displaying its elements.
 */


    for (int j = 0; j < i; j++)
	for (int k = j + 1; k < i; k++) {
	    if (strcmp(array[j], array[k]) > 0) {
		tmp = array[j];
		array[j] = array[k];
		array[k] = tmp;
	    }
	}


    for (int a = 0; a < i; a++) {
	printf("%s\n", array[a]);
	free(array[a]);
    }
    free(array);
    free(direntPtr);
    return 0;
}
