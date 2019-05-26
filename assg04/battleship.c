/*file: battleship.c
 *author: Tristan Caputo
 *purpose: the program takes the board placement of player 1 while player 2 keeps entering guesses to try and sink his ships
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int a[5*2];
int b[4*2];
int s[3*2];
int d[3*2];
int p[2*2];

int isHit(int x, int y)
{ int aflag=0, bflag=0, sflag=0, dflag=0, pflag=0, ahit=0, bhit=0, shit=0, dhit=0, phit=0;
  for (int i=0; i<5; i++)
	if (a[i*2]==x && a[i*2+1]==y)
	{a[i*2]=10; a[i*2+1]=10;ahit=1;}
  for (int i=0; i<9; i++){
	if (a[i] != a[i+1])
		aflag = 1;}

  for (int i=0; i<4; i++)
        if (b[i*2]==x && b[i*2+1]==y)
        {b[i*2]=10; b[i*2+1]=10;bhit=1;}
  for (int i=0; i<7; i++)
        if (b[i] != b[i+1])
                bflag = 1;

  for (int i=0; i<3; i++)
        if (s[i*2]==x && s[i*2+1]==y)
        {s[i*2]=10; s[i*2+1]=10;shit=1;}
  for (int i=0; i<5; i++)
        if (s[i] != s[i+1])
                sflag = 1;

  for (int i=0; i<3; i++)
        if (d[i*2]==x && d[i*2+1]==y)
        {d[i*2]=10; d[i*2+1]=10; dhit=1;}
  for (int i=0; i<5; i++)
        if (d[i] != d[i+1])
                dflag = 1;
 
  for (int i=0; i<2; i++)
        if (p[i*2]==x && p[i*2+1]==y)
        {p[i*2]=10; p[i*2+1]=10; phit=1;}
  for (int i=0; i<3; i++)
        if (p[i] != p[i+1])
                pflag = 1;

 //printf("hit=%d flag=%d\n", bhit, aflag);
  if (aflag==0 && bflag==0 && sflag==0 && dflag==0 && pflag==0)
        {printf("all ships sunk: game over\n");
         exit(0);} 
 if (ahit==1 && aflag==0){
	printf("A sunk\n");
	return 0;}
 if (bhit==1 && bflag==0){
	printf("B sunk\n");
	return 0;}
 if (shit==1 && sflag==0){
	printf("S sunk\n");
	return 0;}
 if (dhit==1 && dflag==0){
	printf("D sunk\n");
	return 0;}
 if (phit==1 && pflag==0){
	printf("P sunk\n");
	return 0;}
 if (ahit==1|| bhit==1||shit==1||dhit==1||phit==1)
 	return 1;
return 0;

}


int main (void)
{
int scanner, lowValue;
char boatType;
int size,error;
int board[10][10];
int count=0;
for (int i=0; i<10; i++)
	for (int j=0; j<10 ; j++)
		board [i] [j] = 0;

int x1, y1, x2, y2;
int xtarget, ytarget;
while (count<5)
{scanf("%s %d %d %d %d",&boatType, &x1, &y1, &x2, &y2);
 if (0>x1 || x1>9 || 0>x2 || x2>9) //ERROR: Out-Of-Bounds
 {
	fprintf(stderr, "Please keep x coordinates in bounds of board..\n");
	return 1;
 }

 if (0>y1 || y1>9 || 0>y2 || y2>9) //ERROR: Out-Of-Bounds
 {
	fprintf(stderr, "Please keep y coordinates in bounds of board..\n");
	return 1;
 }

 if (x2 != x1 && y1 != y2)      //ERROR : parallels
 {
 	fprintf(stderr, "Ships must be parallel to x or y axis..\n");
	return 1;
 }
 
 if (y2>y1){
	size = y2-y1+1;
	lowValue = y1;}
 if (y1>y2){
	size = y1-y2+1;
	lowValue = y2;}
 if (x2>x1){
	size = x2-x1+1;
	lowValue = x1;}
 if (x1>x2){
	size = x1-x2+1;
	lowValue = x2;}  

 if ((boatType=='A' && size != 5) || (boatType=='B' && size != 4) || ((boatType=='D'||boatType=='S') && size != 3) || (boatType=='P' && size!=2))  
	{
		fprintf(stderr, "ship is wrong size\n");
		error = 1;
	}

 if (y1==y2) 				// horizontal
	for (int i=0; i<size; i++)
		{ if (board [9-y1] [lowValue+i] == 1  )
		  {	fprintf(stderr, "ERROR: Ships are overlapping\n");
			error=1;}
		  if (boatType == 'A'){
			a[i*2] = lowValue+i;
			a[(i*2)+1] = y1;}
		  if (boatType == 'B'){
                        b[i*2] = lowValue+i;
                        b[(i*2)+1] = y1;}
		  if (boatType == 'S'){
                        s[i*2] = lowValue+i;
                        s[(i*2)+1] = y1;}
		  if (boatType == 'D'){
                        d[i*2] = lowValue+i;
                        d[(i*2)+1] = y1;}
		  if (boatType == 'P'){
                        p[i*2] = lowValue+i;
                        p[(i*2)+1] = y1;}
		board [9-y1] [lowValue+i] = 1;}

 if (x1==x2) 				// vertical
	for (int i=0; i<size; i++)
	{ if (board [9-lowValue-i] [x1] == 1 )
	  {	fprintf(stderr, "ERROR: Ships are overlapping\n");
		error = 1;}
	  if (boatType == 'A'){
		a[i*2]=x1;
		a[(i*2)+1]=lowValue+i;}
	  if (boatType == 'B'){
                b[i*2]=x1;
                b[(i*2)+1]=lowValue+i;}
	  if (boatType == 'D'){
                d[i*2]=x1;
                d[(i*2)+1]=lowValue+i;}
	  if (boatType == 'S'){
                s[i*2]=x1;
                s[(i*2)+1]=lowValue+i;}
	  if (boatType == 'P'){
                p[i*2]=x1;
                p[(i*2)+1]=lowValue+i;}
		board [9-lowValue-i] [x1] = 1;}
count++;  

}

while ((scanner=scanf("%d %d", &xtarget, &ytarget))!=EOF)
{
  if (xtarget > 9 || xtarget < 0 || ytarget > 9 || ytarget < 0)
  {
	fprintf(stderr, "error: illegal guess\n");
	error= 1;
	continue;
  }	
  if (isdigit(xtarget)|| isdigit(ytarget))
  {
	fprintf(stderr, "x and y coordinates are non integers, exiting..\n");
	return 1;
  }
		 
  if (board [9-ytarget] [xtarget] == 0)
	printf("miss\n");

  if (isHit(xtarget,ytarget)==1)
	printf("hit\n");


  


}

return error;
}
