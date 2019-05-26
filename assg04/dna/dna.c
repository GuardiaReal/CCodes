/*
 *file: dna.c
 *author: Tristan Caputo
 *purpose:Matches DNA evidence ( 2 Strings of Integers)
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
char susProfile[1024];
char eviProfile[1024];
int c,d;
int scanner;
int error=0, i=0, posMatch=0;
while ((scanner=scanf("%s %s", susProfile, eviProfile))!=EOF)
{i=0;
 posMatch=0;
	if (strlen(susProfile)!=strlen(eviProfile))
        {
                fprintf(stderr, "ERROR: Input Strings are of different lengths\n");
                return 1;
        }

	while (susProfile[i])
	{c=susProfile[i]-'0';
         d=eviProfile[i]-'0';

		if (c>9 || c<0 || d>9 || d<0)//||isdigit(d)==0)
		{ 	fprintf(stderr, "ERROR: Input String(s) contain characters other than digits\n");
			return 1;}

	if (c > 6 && d > 6)
		posMatch++;
	if (c <= 6 && d <= 6)
		posMatch++;
	i++;
	}


printf("%d\n", posMatch);
}

return error;
}
