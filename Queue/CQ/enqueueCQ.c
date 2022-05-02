#include "circularqueue.h"

int enqueueCQ(CircularQueue *pQueue, CircularQueueNode element)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}
	if (isCircularQueueFull(pQueue))
	{
		printf("[error] Queue is already full.\n");
		return (FALSE);
	}
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
}
