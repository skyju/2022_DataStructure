#ifndef _LINKEDSTACK_
#define _LINKEDSTACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LinkedStackNodeType
{
	char data;
	struct LinkedStackNodeType *next;
} LinkedStackNode;

typedef struct LinkedStackType
{
	int count;
	LinkedStackNode *head;
} LinkedStack;

#define TRUE	1
#define FALSE	0
#endif