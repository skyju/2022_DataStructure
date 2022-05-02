#include <stdlib.h>
#include "linkedqueue.h"

LinkedQueue	*createLinkedQueue(void)
{
	LinkedQueue	*queue;

	queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!queue)
		return (0);
	queue->currentElementCount = 0;
	queue->front = 0;
	queue->rear = 0;
	return (queue);
}
