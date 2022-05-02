#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

#include <stdlib.h>
#include <stdio.h>

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* left;
	struct DoublyListNodeType* right;
} DoublyListNode;

typedef struct DoublyListType
{
	int currentElementCount;
	DoublyListNode head;
} DoublyList;

DoublyList* createDoublyList();
int addDLElement(DoublyList* list, int index, DoublyListNode element);
int removeDLElement(DoublyList* list, int index);
DoublyListNode* getDLElement(DoublyList* list, int index);
void displayDoublyList(DoublyList* list);
void clearDoublyList(DoublyList* list);
int getDoublyListLength(DoublyList* list);
void deleteDoublyList(DoublyList** list);
int replaceDLElement(DoublyList* list, int index, DoublyListNode element);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
