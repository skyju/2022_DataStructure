#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedListNodeType
{
	double coef;
	int	degree;
	struct LinkedListNodeType* next;
} PolyListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	PolyListNode head;
} PolyList;

PolyList* createPolyList();
int addPLElement(PolyList* list, int index, PolyListNode data);
int removePLElement(PolyList* list, int index);
PolyListNode* getPLElement(PolyList* list, int index);
void displayPolyList(PolyList* list);
void clearPolyList(PolyList* list);
int getPolyListLength(PolyList* list);
void deletePolyList(PolyList** list);

int addPolyNodeLast(PolyList* list, double coef, int degree);
PolyList* polyAddCal(PolyList* a, PolyList* b);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif