#include "arrayqueue.h"

int	enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue || isArrayQueueFull(pQueue))
		return (FALSE);
	pQueue->rear++;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (1);
}
