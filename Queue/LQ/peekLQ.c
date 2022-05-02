#include "linkedqueue.h"

LinkedQueueNode	*peekLQ(LinkedQueue *pQueue)
{
	LinkedQueueNode	*Node;

	if(!pQueue || isLinkedQueueEmpty(pQueue))
		return (0);
	Node = pQueue->front;
	return (Node);
}
