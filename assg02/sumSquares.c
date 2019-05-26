/*
 *File: sumSquares.c
 *author: Tristan Caputo
 *Purpose: Given two integers, this program will find which number betweeen those integers
 *         can be represented as a sum of two square numbers (N = p^2 + r^2)
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int m;
	int n;
  	int scanner = scanf("%d %d",  &m, &n);	
	if (scanner != 2)
	{
		fprintf(stderr, "ERROR: non-integer detected! Exiting..\n");
		return 1;
	} 
        if (m>n)
	{
		return 0;
	}
	if (m <= 0 || n <= 0)
	{
		fprintf(stderr, "ERROR: one or both of the integers are not positive\n");
		return 1;
	}
	int i, a, b;	
	for (i=m; i<=n; i++)
	{	
		for (a=1; a<n; a++)
		{
			for (b=n; b>0; b--)
			{
				if (a==b+1)
					break;
				if (i == (a*a) + (b*b))
				{  
					printf("%d\n", i);
					i++;
				}
		
			}
		
		}	
 	
	}
	return 0;
}	
