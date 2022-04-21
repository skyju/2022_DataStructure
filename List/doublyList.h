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
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode head;		// 헤더 노드(Header Node)
} DoublyList;

DoublyList* createDoublyList();
int addDLElement(DoublyList* list, int index, DoublyListNode element);
int removeDLElement(DoublyList* list, int index);
DoublyList* getDLElement(DoublyList* list, int index);
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
