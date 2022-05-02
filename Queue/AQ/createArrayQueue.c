#include "arrayqueue.h"

ArrayQueue *createArrayQueue(int maxElementCount)
{
	ArrayQueue *arrayqueue;

	if (maxElementCount <= 0)
	{
		printf("[error] Invalid count number.\n");
		return (NULL);
	}
	arrayqueue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (!arrayqueue)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	arrayqueue->maxElementCount = maxElementCount;
	arrayqueue->currentElementCount = 0;
	arrayqueue->front = -1;
	arrayqueue->rear = -1;
	arrayqueue->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
	if (!arrayqueue->pElement)
	{
		printf("[error] Memory allocate failed.\n");
		free(arrayqueue);
		arrayqueue = NULL;
		return (NULL);
	}
	return (arrayqueue);
}
