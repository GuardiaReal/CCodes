#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
int dif = 'a' - 'A';
char *myString, *ptr;
char *str = {0};
myString = (char *) malloc (strlen(str)+1);
scanf("%s", str);
strcpy(myString, str);
ptr = myString;

for (int i=0; i<strlen(myString); i++)
{
	if (*ptr>='A' && *ptr <= 'Z')
		*ptr = *ptr+dif;

*(ptr++);

}
printf("%s\n", myString);
return 0;

}
