#include "arrayqueue.h"

ArrayQueueNode *peekAQ(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isArrayQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	return (&(pQueue->pElement[pQueue->front + 1]));
}
