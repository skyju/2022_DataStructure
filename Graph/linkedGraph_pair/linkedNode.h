#ifndef _LINKEDNODE_
#define _LINKEDNODE_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct GraphVertexType
{
	int vertexID;
	int weight;
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType *pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

LinkedList *createLinkedList();

int addLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode *getLLElement(LinkedList *pList, int position);
ListNode	*createNode(ListNode element);

void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif