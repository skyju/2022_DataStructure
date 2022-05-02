#include "linkedqueue.h"

LinkedQueue *createLinkedQueue(void)
{
	LinkedQueue *queue;

	queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!queue)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	queue->currentElementCount = 0;
	queue->front = 0;
	queue->rear = 0;
	return (queue);
}
