#include <stdlib.h>
#include "linkedqueue.h"

LinkedQueueNode	*dequeueLQ(LinkedQueue *pQueue)
{
	LinkedQueueNode	*Node;

	if (!pQueue || isLinkedQueueEmpty(pQueue))
		return (0);
	if (pQueue->currentElementCount == 1)
	{
		pQueue->rear = 0;
	}
	else
	{
		Node = pQueue->front;
		pQueue->front = pQueue->front->pLink;
		Node->pLink = 0;
	}
	pQueue->currentElementCount--;
	return (Node);
}
