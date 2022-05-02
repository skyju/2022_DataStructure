#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LinkedQueueNodeType
{
	char data;
	struct LinkedQueueNodeType *next;
} LinkedQueueNode;

typedef struct LinkedQueueType
{
	int count;
	LinkedQueueNode *front;
	LinkedQueueNode *rear;
} LinkedQueue;

LinkedQueue *createLinkedQueue();
int enqueueLQ(LinkedQueue *pQueue, LinkedQueueNode element);
LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue);
LinkedQueueNode *peekLQ(LinkedQueue *pQueue);
void deleteLinkedQueue(LinkedQueue **pQueue);
int isLinkedQueueEmpty(LinkedQueue *pQueue);
void displayLinkedQueue(LinkedQueue *pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif