#include "circularqueue.h"

int	isCircularQueueEmpty(CircularQueue *pQueue)
{
	if (pQueue->currentElementCount == 0 || pQueue->rear == pQueue->front)
		return (1);
	return (0);
}
