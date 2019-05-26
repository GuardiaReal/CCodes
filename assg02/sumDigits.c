/*File: sumDigits.c
 *Author: Tristan Caputo
 *purpose: for each given number, this program returns the sum of its digits
 */
#include <stdio.h>
int addDigits(int m);
int main(void)
{
 int n;
 int scanner;
 while ((scanner=scanf("%d", &n))!= EOF)
 {
 int m=addDigits(n);
 if (scanner!=1)
 {
	fprintf(stderr, "ERROR: Input is a non-integer! Exiting..\n");
	return 1;
 }

 if (m!=-1) 
 	printf("%d\n", m);
 }
  
 return 0;
}

/*
 *this sum returns the sum of digits of m
 */
int addDigits(int m)
{
 int sum = 0;
 int r =0;
 if (m<=0)
 {
  	fprintf(stderr, "ERROR: Integer is 0 or negative\n");
	return -1;
 }



 while (m != 0)
 {
	r=m%10;
        sum = sum+r;
	m = m/10;

 }
 return sum;
}
