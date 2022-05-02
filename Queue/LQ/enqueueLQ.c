#include <stdlib.h>
#include "linkedqueue.h"

int	enqueueLQ(LinkedQueue *pQueue, LinkedQueueNode element)
{
	LinkedQueueNode	*Node;

	if (!pQueue)
		return (0);
	Node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	if (!Node)
		return (0);
	Node->data = element.data;
	if (isLinkedQueueEmpty(pQueue))
	{
		pQueue->front = Node;
		pQueue->rear = Node;
	}
	else
	{
		pQueue->rear->pLink = Node;
		pQueue->rear = Node;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}
