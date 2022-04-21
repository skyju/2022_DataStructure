#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

#include <stdlib.h>
#include <stdio.h>

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType* next;
} CircularListNode;

typedef struct CircularListType
{
	int currentCount;	// 현재 저장된 원소의 개수
	CircularListNode head;		// 헤더 노드(Header Node)
} CircularList;

CircularList* createCircularList();
int addCLElement(CircularList* list, int index, CircularListNode element);
int removeCLElement(CircularList* list, int index);
CircularListNode* getCLElement(CircularList* list, int index);
void displayCircularList(CircularList* list);
void clearCircularList(CircularList* list);
int getCircularListLength(CircularList* list);
void deleteCircularList(CircularList** list);
int replaceCLElement(CircularList* list, int index, CircularListNode element);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
