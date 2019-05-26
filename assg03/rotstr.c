/*
 *file: rotstr.c 
 *author: Tristan Caputo
 *purpose: takes in an integer N and 0 or more alphanumerics and rotates the substitution cipher to represent these alphanumerics under encrypted view
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int rotate (char word[], int n)
{
int i=0;
int index; 
const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
const char *bigalpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
while (word[i])
{
 if (isdigit(word[i]))
	{printf("%c", word[i]);
       	 i++;
	 continue;}
 if (islower(word[i])){
  index = strchr(alphabet, word[i])-alphabet;
 if (index<0)
	fprintf(stderr, "ERROR: Not found\n");	
 if ((index+n)>=0)
	printf("%c",alphabet[index+n]);
 	
 if ((index+n)<=0)
		{index = (index+1)%26;
 	 	printf("%c", alphabet[25+index+n]);}
 }

 if (isupper(word[i])){

 index = strchr(bigalpha, word[i])-bigalpha;
 if (index<0)
        fprintf(stderr, "ERROR: Not found\n");
 if ((index+n)>=0)
        printf("%c", bigalpha[index+n]);
 if ((index+n)<=0)
        {       index = (index+1)%26;
                printf("%c", bigalpha[25+index+n]);}
 }
 if (word[i]==' ')
	printf(" ");
i++;
}
printf("\n");
return 0;
}


int main (void)
{
int d= -9999;
int i, scanner;
int errorna =0;
char word[65];
scanf("%d" , &d);
while ((scanner=scanf("%s", word))!=EOF)
{i=0;
	 
 if (d==-9999)
 {fprintf(stderr, "ERROR: No integer detected ! Exiting..\n");
  return 1;}	
	if (d==0)
		{printf("%s\n", word);
		 continue;}	
	while (word[i])
	{
		if (!isalnum(word[i]))	
		{
		fprintf(stderr, "ERROR: String contains non-alphanumeric !\n");
	        errorna =1;		
		break;
		}
  	i++;		
	}
	rotate(word, d);

} 
if (errorna==1)
	return 1;
return 0;

}


