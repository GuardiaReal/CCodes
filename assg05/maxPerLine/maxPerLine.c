/*
 *file: maxPerLine.c
 *author: Tristan Caputo
 *purpose: takees in a stream of numbers in zero or multiple lines and prints the biggest number per line
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main (void)
{
int error=0;
size_t len=1024;
char pointer;
char *myString;
int bigNumber=0;
int d;
myString = (char *) malloc (len+1);

while (getline (&myString, &len, stdin)>0)
{error=0; 
  sscanf(myString, "%s",  &pointer);
  int len = strlen(myString);
  for (int i=0; i<=len; i++)
  {   	 
  if (isspace(myString[i]))
	i++;
  sscanf(myString+i, "%s",  &pointer);
  d = atoi(&pointer);
  
  if (d>bigNumber)
	bigNumber = d;
  
  if (isdigit(pointer-'0')>0)
	{error=1;
	fprintf(stderr, "Error:Non-integer value detected\n");
	break;}
  if (myString[0]=='\n')
	{error=1;
	fprintf(stderr, "Error: newline\n");
        break;
	}

  }
  if (error==1)
	continue;
  
 printf("%d\n", bigNumber);
 bigNumber=0;    // reset bigNumber to 0 for next line input 
}



return error;
}
