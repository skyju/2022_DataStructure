#include <stdlib.h>
#include "arrayqueue.h"

ArrayQueue	*createArrayQueue(int maxElementCount)
{
	ArrayQueue	*arrayqueue;

	if (maxElementCount < 0)
		return (0);
	arrayqueue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (!arrayqueue)
		return (0);
	arrayqueue->maxElementCount = maxElementCount;
	arrayqueue->currentElementCount = 0;
	arrayqueue->front = -1;
	arrayqueue->rear = -1;
	arrayqueue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!arrayqueue->pElement)
	{
		free(arrayqueue);
		arrayqueue = 0;
		return (0);
	}
	return (arrayqueue);
}
