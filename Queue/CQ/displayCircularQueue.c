#include "circularqueue.h"

void displayCircularQueue(CircularQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if (isCircularQueueEmpty(pQueue))
	{
		printf("Queue is empty.. \n");
		return;
	}
	int i;
	for (int idx = pQueue->front + 1; idx <= pQueue->front + pQueue->currentElementCount; idx++)
	{
		i = idx % pQueue->maxElementCount;
		printf("%c", pQueue->pElement[i].data);
	}
}
