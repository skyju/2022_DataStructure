#include <stdlib.h>
#include "circularqueue.h"

CircularQueueNode	*dequeueCQ(CircularQueue *pQueue)
{
	CircularQueueNode	*Node;

	if (!pQueue || isCircularQueueEmpty(pQueue))
		return (FALSE);
	Node = (CircularQueueNode *)malloc(sizeof(CircularQueueNode));
	if (!Node)
		return (FALSE);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	Node->data = pQueue->pElement[pQueue->front].data;
	pQueue->pElement[pQueue->front].data = 0;;
	pQueue->currentElementCount--;
	return (Node);
}
