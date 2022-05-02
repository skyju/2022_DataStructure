#include "arrayqueue.h"

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isArrayQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	
	ArrayQueueNode *node;
	node = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!node)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}

	pQueue->front++;
	*node = pQueue->pElement[pQueue->front];
	pQueue->pElement[pQueue->front].data = 0;
	pQueue->currentElementCount--;
	return (node);
}
