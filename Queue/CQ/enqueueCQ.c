#include "circularqueue.h"

int	enqueueCQ(CircularQueue *pQueue, CircularQueueNode element)
{
	if (!pQueue || isCircularQueueFull(pQueue))
		return (FALSE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
}
