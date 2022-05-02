#include "arrayqueue.h"

int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}
	if (isArrayQueueFull(pQueue))
	{
		printf("[error] Queue is already full.\n");
		return (FALSE);
	}
	pQueue->rear++;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
}
