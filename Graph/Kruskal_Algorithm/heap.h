#ifndef _HEAP_
#define _HEAP_

#include "LinkedGraphList.h"
#include "linkedNode.h"

typedef struct HeapNodeType
{
	int vertexID_1;
	int vertexID_2;
	int weight;
} HeapNode;

typedef struct HeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	HeapNode *pElement;	// 원소 저장을 위한 1차원 배열
} Heap;

Heap* createHeap(int maxElementCount);
void deleteHeap(Heap** pHeap);
void insertMinHeap_weight(Heap* pHeap, HeapNode node);
void deleteMinHeap_weight(Heap* pHeap);
void displayHeap(Heap* pHeap);

HeapNode *pop_zero(Heap *heap);
HeapNode peek_zero(Heap *heap);

#endif

#ifndef _HEAP_DEF_
#define _HEAP_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif