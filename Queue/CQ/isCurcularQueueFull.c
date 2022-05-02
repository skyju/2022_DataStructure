#include "circularqueue.h"

int	isCircularQueueFull(CircularQueue *pQueue)
{
	//if ((pQueue->rear + 1) % pQueue->maxElementCount == pQueue->front)
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return (TRUE);
	return (FALSE);
}
