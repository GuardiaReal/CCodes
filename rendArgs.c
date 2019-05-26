#include <stdio.h>

int main (int argc, char*argv[])
{
for (int i=1; i<argc; i++)       // i = 1 because we do not wanna print "NAME OF PROGRAM"
	printf("%s\n", argv[i]);


return 0;
}
