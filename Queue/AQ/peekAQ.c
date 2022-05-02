#include "arrayqueue.h"

ArrayQueueNode	*peekAQ(ArrayQueue *pQueue)
{
	ArrayQueueNode	*pNode;

	if (!pQueue || isArrayQueueEmpty(pQueue))
		return (0);
	pNode = &pQueue->pElement[pQueue->front];
	return (pNode);
}
