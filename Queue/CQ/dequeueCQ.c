#include "circularqueue.h"

CircularQueueNode *dequeueCQ(CircularQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isCircularQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}

	CircularQueueNode *node;
	node = (CircularQueueNode *)malloc(sizeof(CircularQueueNode));
	if (!node)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}

	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	*node = pQueue->pElement[pQueue->front];
	pQueue->pElement[pQueue->front].data = 0;
	pQueue->currentElementCount--;
	return (node);
}
