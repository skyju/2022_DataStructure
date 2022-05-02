#include "circularqueue.h"

int	isCircularQueueFull(CircularQueue *pQueue)
{
	if ((pQueue->rear + 1) % pQueue->maxElementCount == pQueue->front)
		return (1);
	return (0);
}
