#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ArrayStackNodeType
{
	char data;
} ArrayStackNode;

typedef struct ArrayStackType
{
	int max_size;
	int count;
	ArrayStackNode *arr;
} ArrayStack;

#define TRUE	1
#define FALSE	0
#endif