#include <stdlib.h>
#include "circularqueue.h"

CircularQueue	*createCircularQueue(int maxElementCount)
{
	CircularQueue	*circularqueue;

	if (maxElementCount < 0)
		return (0);
	circularqueue = (CircularQueue *)malloc(sizeof(CircularQueue));
	if (!circularqueue)
		return (0);
	circularqueue->maxElementCount = maxElementCount;
	circularqueue->currentElementCount = 0;
	circularqueue->front = 0;
	circularqueue->rear = 0;
	circularqueue->pElement = (CircularQueueNode *)malloc(sizeof(CircularQueueNode) * maxElementCount);
	if (!circularqueue->pElement)
	{
		free(circularqueue);
		circularqueue = 0;
		return (0);
	}
	return (circularqueue);
}
