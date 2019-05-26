/*
 *file: median.c
 *author: Tristan Caputo
 *purpose: reads input values and prints out the median as a floating point value
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
float median=0;
int error=0;
int d;
int size = 0;
int scanner = 0;
int *array = (int*) malloc(size*sizeof(int));
int i, j;
while ((scanner=scanf("%d", &array[size]))!=EOF)
{
  if (isdigit(array[size]))
  {	fprintf(stderr, "ERROR: Non-Integer value detected !\n");
	error=1;
	return error;} 
 size++;}


for (i=0; i<size; i++){
	for (j=0; j<size-i-1; j++)
	{	if (array[j+1] < array[j])
		{	d = array[j];
			array[j] = array[j+1];
			array[j+1] = d;
		}
	}
}

if (size == 0)
{	fprintf(stderr, "ERROR: No input detected!\n");
	error=1;
	return error;}
if (size%2 != 0)
	median = array[size/2];

if (size%2 == 0)
	median = (array[size/2] + array[size/2 - 1])/2.0; 
if (median > 0)  
	printf("%f\n", median);
return error;
}
