#include "circularqueue.h"

CircularQueueNode	*peekCQ(CircularQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isCircularQueueEmpty(pQueue))
	{
		printf("[error] Queue is already full.\n");
		return (NULL);
	}
	return (&pQueue->pElement[pQueue->front + 1]);
}
