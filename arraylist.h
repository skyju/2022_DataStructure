#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayListNode *array;	// 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
int addALElement(ArrayList* list, int index, ArrayListNode element);
int removeALElement(ArrayList* list, int index);
ArrayListNode* getALElement(ArrayList* list, int index);
void displayArrayList(ArrayList* list);
int isArrayListFull(ArrayList* list);
void clearArrayList(ArrayList* list);
int getArrayListLength(ArrayList* list);
void deleteArrayList(ArrayList** list);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif

//배열 <-> 배열리스트 : 자료가 일직선으로 서로 연결 되어있어야함(중간에 끊기면 안됨)