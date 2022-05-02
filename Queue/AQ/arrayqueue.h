#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;
	int currentElementCount;
	int front;				  // front 위치
	int rear;				  // rear 위치
	ArrayQueueNode *pElement; // 자료 저장을 위한 1차원 배열 포인터
} ArrayQueue;

ArrayQueue *createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue);
ArrayQueueNode *peekAQ(ArrayQueue *pQueue);
void deleteArrayQueue(ArrayQueue *pQueue);
int isArrayQueueFull(ArrayQueue *pQueue);
int isArrayQueueEmpty(ArrayQueue *pQueue);
void displayArrayQueue(ArrayQueue *pQueue);
void displayQueue(ArrayQueue *pQueue);
int repositionAQ(ArrayQueue *pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif
