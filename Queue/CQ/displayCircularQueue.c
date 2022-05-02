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
	int idx;
	idx = pQueue->front;
	while (idx != pQueue->rear)
	{
		idx = (idx + 1) % pQueue->maxElementCount;
		printf("%c", pQueue->pElement[idx].data);
	}
}
