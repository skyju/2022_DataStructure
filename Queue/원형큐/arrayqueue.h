#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxCount;	  // 큐 최대 원소 개수
	int currentCount;  // 현재 원소 개수
	int front;				  // 프런트 위치
	int rear;				  // 리어 위치
	ArrayQueueNode *arr; // 자료를 저장하는 1차원 배열 포인터
} ArrayQueue;

ArrayQueue *createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue);
ArrayQueueNode *peekAQ(ArrayQueue *pQueue);
void deleteArrayQueue(ArrayQueue **pQueue);
int isArrayQueueFull(ArrayQueue *pQueue);
int isArrayQueueEmpty(ArrayQueue *pQueue);
void displayArrayQueue(ArrayQueue *pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif