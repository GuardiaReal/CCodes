
/*
 *file: jdec.c
 *author: Tristan Caputo
 *purpose: Works as a java decompiler using a stack and a binary tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* GLOBALS*/

struct stackNode *stackTop = NULL;
int len = 1;

/*tree node struct which contains a char pointer as well as two tree node pointers 
 *acting as childs.*/
struct treeNode
{
char *msg;
struct treeNode *leftChild, *rightChild;
};

/*stack node which contains a tree node pointer as its value as well as a next stack 
 *node pointer.*/ 
struct stackNode
{
struct treeNode *val;
struct stackNode *next;
};

struct treeNode *newSyntaxTreeNode()
{
	struct treeNode *tnode;
	tnode = malloc(sizeof(struct treeNode));
	return tnode;
}

void dumpTree (struct treeNode *ptr)
{
if (ptr == NULL)
	return;
if (strcmp(ptr->msg,"+")==0 || strcmp(ptr->msg,"*")==0 || strcmp(ptr->msg,"-")==0 || strcmp(ptr->msg,"/")==0){
	printf("(");
	dumpTree(ptr->leftChild);
	printf("%s", ptr->msg);
	dumpTree(ptr->rightChild);
	printf(")");
	return;
	}
else 
	printf("%s", ptr->msg);
return;

}

/*this method check if the stack is empty, it returns 1 if it is , 0 if it isn't.*/
int isempty(void)
{
if (len<=1)
        return 1;
return 0;
}

/*this method pushes a new stack node containing our passed tree node element onto the 
 *stack. It takes in a tree node pointer and returns void.*/
void push (struct treeNode *node)
{
	struct stackNode *ptr = (struct stackNode *)malloc (sizeof(struct stackNode));
	ptr->val = node;
	ptr->next = stackTop;
	stackTop = ptr;
	len++;
	return;
}

/*this method pops the top element of the stack and makes the next element, the new top.*/
struct treeNode *pop(void)
{
	struct treeNode *tptr;
	struct stackNode *sptr;
	sptr = stackTop;
	stackTop = stackTop->next;
	tptr = sptr->val;
	free(sptr);
	len--;
	return tptr;
}


int main (void)
{
int error=0, flag=0;
size_t size = 1;
char *myString, *token=NULL;
struct treeNode *temp;
myString = (char *) malloc(sizeof(char));

while (getline(&myString, &size, stdin)>0)
{
	token = strtok(myString, " \t\n");

	while (token !=  NULL)
	{
	if (strcmp(token,"iload")==0){
		flag=0;
		temp = newSyntaxTreeNode();
		token = strtok(NULL, " \t\n");
		temp->msg = strdup(token);
		temp->leftChild = NULL;
		temp->rightChild = NULL;
		if (isdigit(*token)<=0)
			push(temp);

		if (isdigit(*token)>0){
			fprintf(stderr, "ERROR: Invalid token for 'iload', exiting..\n");
			exit(1);
		}}
	
	else if (strcmp(token, "iconst")==0)
		{
		flag=0;
                temp = newSyntaxTreeNode();
		token = strtok(NULL, " \t\n");
		temp->msg = strdup(token);
		temp->leftChild = NULL;
		temp->rightChild = NULL;
		if (isdigit(*token)>0)
                	push(temp);

		if (isdigit(*token)<=0){
			fprintf(stderr, "ERROR: Invalid token for 'iconst',exiting..\n");
			exit(1);}}
	
	else if(strcmp(token, "iadd")==0){
		if (flag==1)
		{	printf("ERROR: Cannot perform this operation without more tokens\n");
			exit(1);
			
		}
		flag=1;
		temp = newSyntaxTreeNode();
		temp->msg = "+";
		temp->leftChild = pop();
		temp->rightChild = pop();
		push(temp);}

	else if (strcmp(token, "imul")==0)
	{	if (flag==1)
                {       printf("ERROR: Cannot perform this operation without more tokens\n");
                        exit(1);

                }
		flag=1;
		temp = newSyntaxTreeNode();
		temp->msg = "*";
		temp->leftChild = pop();
		temp->rightChild = pop();
                push(temp);}

	else if (strcmp(token, "isub")==0)
	{  	if (flag==1)
                {       printf("ERROR: Cannot perform this operation without more tokens\n");
                        exit(1);

                }
		flag=1;
		temp = newSyntaxTreeNode();
		temp->msg = "-";
		temp->leftChild = pop();
		temp->rightChild = pop();
		push(temp);
	}
		
	else if (strcmp(token, "idiv")==0)
	{      	if (flag==1)
                {       printf("ERROR: Cannot perform this operation without more tokens\n");
                        exit(1);

                }
		flag=1;
		temp = newSyntaxTreeNode();
		temp->msg = "/";
		temp->leftChild = pop();
		temp->rightChild = pop();
		push(temp);}
						

	else
	{printf("ERROR: Invalid Input: %s\n", token);
	return 1;}

	token = strtok(NULL, " \t\n");	
	}
	
}
	temp = pop();
	if(isempty()==0){
		fprintf(stderr, "ERROR: Stack is not empty, exiting..\n");
		exit(1);}

	dumpTree(temp);
	printf("\n");
	return error;
}
