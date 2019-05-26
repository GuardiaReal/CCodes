/*
 *file: rpn.c
 *author: Tristan Caputo
 *purpose: represents a calculator using Reverse Polish Notation 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *stackTop = NULL;

/*this method pushes a node holding an int element onto our stack*/
void push(int x)
{
    Node *nptr;
    nptr = malloc(sizeof(Node));
    nptr->val = x;
    nptr->next = stackTop;
    stackTop = nptr;
    return;
}

/*int isempty(void)
{
if (stackTop==NULL)
	return 1;
return 0; 
}*/

/*this method pops a node holding an int off our stack and returns that int*/
int pop(void)
{
    if (stackTop == NULL) {
	printf("ERROR: Not enough operands\n");
	exit(1);
    }
    int b = stackTop->val;
    stackTop = stackTop->next;
    return b;
}

int main(void)
{
    int error = 0;
    int x, y, value;
    size_t size = 1;
    char *myString = NULL, *token = NULL, *ptr;
    int b;
    while (getline(&myString, &size, stdin) > 0) {
	error = 0;
	token = strtok(myString, " ");
	while (token != NULL) {

	    if (isdigit(*token) != 0) {
		b = strtol(token, &ptr, 10);
		if (*ptr) {
		    printf("ERROR: Invalid Input Detected !\n");
		    error = 1;
		    break;
		}
		push(b);
	    }

	    else if (*token == '+' || *token == '-' || *token == '*'
		     || *token == '/') {
		{
		    x = pop();
		    y = pop();
		}

		switch (*token) {
		case '+':
		    value = x + y;
		    push(value);
		    break;
		case '-':
		    value = y - x;
		    push(value);
		    break;
		case '*':
		    value = x * y;
		    push(value);
		    break;
		case '/':
		    value = y / x;
		    push(value);
		    break;
		}
	    }

	    else {
		fprintf(stderr, "ERROR: Invalid Input Detected !\n");
		error = 1;
		break;
	    }

	    token = strtok(NULL, " ");

	}

	if (error == 0)
	    printf("%d\n", value);

    }
    return error;
}
