#include "circularqueue.h"

CircularQueue *createCircularQueue(int maxElementCount)
{
	CircularQueue *circularqueue;

	if (maxElementCount <= 0)
	{
		printf("[error] Invalid count number.\n");
		return (NULL);
	}
	circularqueue = (CircularQueue *)malloc(sizeof(CircularQueue));
	if (!circularqueue)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	circularqueue->maxElementCount = maxElementCount;
	circularqueue->currentElementCount = 0;
	circularqueue->front = -1;
	circularqueue->rear = -1;
	circularqueue->pElement = (CircularQueueNode *)calloc(maxElementCount, sizeof(CircularQueueNode));
	if (!circularqueue->pElement)
	{
		printf("[error] Memory allocate failed.\n");
		free(circularqueue);
		circularqueue = NULL;
		return (NULL);
	}
	return (circularqueue);
}
