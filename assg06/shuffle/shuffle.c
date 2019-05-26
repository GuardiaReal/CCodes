/*
 *file: shuffle.c
 *author: Tristan Caputo
 *purpose: takes in a stream of integers and shuffles them in riffle shuffle and prints out their order
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
char *buf1;
char *buf2;
char *token=NULL;
char *ptr;
size_t len = 1024;
int i=0, j=0;
int array1[128];
int array2[128];
int counter = 0;
buf1 = (char*)malloc(len+1);
buf2 = (char*)malloc(len+1);

fgets(buf1, len, stdin);
fgets(buf2, len, stdin);

  if (buf1!=NULL && buf2!=NULL)
  	if (buf1[0] == '\n' && buf2[0] == '\n')
		return 0;

if (buf1[0] != '\n')
	token = strtok(buf1, " ");

while (token != NULL)
{	array1[i] = strtol(token, &ptr, 10);
	if (ptr[0] != '\n' && *ptr){
		printf("ERROR: Invalid Input Detected!\n");
		return 1;}
	token = strtok(NULL, " ");
	i++;
}
if (buf2[0] != '\n')
	token = strtok(buf2, " ");

while (token != NULL)
{	array2[j] = strtol(token, &ptr, 10);
	token = strtok(NULL, " ");
	j++;
}


while (counter < i || counter < j)
{
	if (counter < i)
		printf("%d\n", array1[counter]);
	if (counter < j)
		printf("%d\n", array2[counter]);
counter++;
}


return 0;
}
