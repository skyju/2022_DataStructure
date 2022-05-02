#include <stdlib.h>
#include "arrayqueue.h"

ArrayQueueNode	*dequeueAQ(ArrayQueue *pQueue)
{
	ArrayQueueNode	*Node;

	if (!pQueue || isArrayQueueEmpty(pQueue))
		return (0);
	Node = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!Node)
		return (0);
	pQueue->front++;
	Node->data = pQueue->pElement[pQueue->front].data;
	pQueue->pElement[pQueue->front].data = 0;
	pQueue->currentElementCount--;
	return (Node);
}
