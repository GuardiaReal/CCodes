/*
 * File: isFib.c
 * Author: Tristan Caputo
 * Purpose: takes in a stream of integers and tells us which ones are Fibonacci numbers
 */
#include<stdio.h>
#include<math.h>

/*isFib(int n) -- returns 1 if n is a Fibonacci number and 0 otherwise
 *
 */

int isFib(int n)
{
 int op1, op2, x, s;
 if (n<=0)
 	return 2; 
 op1 = 5*n*n+4;
 op2 = 5*n*n-4;
 
  x = sqrt(op1);
  s = sqrt(op2);
 if (op1 == x*x)
	return 1;
 if (op2 == s*s)
	return 1;
 return 0;
}

int main(void)
{
 int n=0;
 int scanner;
 while ((scanner=scanf("%d", &n))!=EOF)
 {
 if (scanner!=1)
 {	fprintf(stderr, "ERROR:input is a non-integer! Exiting.. \n");	 
	return 1;}
 if (isFib(n)==1)
	printf("%d is fib\n", n);
 if (isFib(n)==0)
	printf("%d is not fib\n", n);
 if (isFib(n)==2)
	fprintf(stderr, "ERROR: Integer value is a non-positive\n");
 }	
 return 0;
}
