#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* next;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode head;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* list, int index, ListNode element);
int removeLLElement(LinkedList* list, int index);
ListNode* getLLElement(LinkedList* list, int index);
void displayLinkedList(LinkedList* list);
void clearLinkedList(LinkedList* list);
int getLinkedListLength(LinkedList* list);
void deleteLinkedList(LinkedList** list);
int replaceLLElement(LinkedList* list, int index, ListNode element);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif