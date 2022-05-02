#include "linkedqueue.h"

int enqueueLQ(LinkedQueue *pQueue, LinkedQueueNode element)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}

	LinkedQueueNode *node;
	node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	if (!node)
	{
		printf("[error] Memory allocate failed.\n");
		return (FALSE);
	}

	*node = element;
	node->pLink = NULL;
	if (isLinkedQueueEmpty(pQueue) == 1)
	{
		pQueue->front = node;
		pQueue->rear = node;
	}
	else
	{
		pQueue->rear->pLink = node;
		pQueue->rear = node;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}
