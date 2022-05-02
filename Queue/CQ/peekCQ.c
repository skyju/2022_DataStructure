#include "circularqueue.h"

CircularQueueNode	*peekCQ(CircularQueue *pQueue)
{
	if (!pQueue || isCircularQueueEmpty(pQueue))
		return (FALSE);
	return (&pQueue->pElement[pQueue->front]);
}
