#include "circularqueue.h"

void deleteCircularQueue(CircularQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if (pQueue->pElement)
		free(pQueue->pElement);
	free(pQueue);
	pQueue = NULL;
}
