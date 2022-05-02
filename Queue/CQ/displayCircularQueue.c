#include <stdio.h>
#include "circularqueue.h"

void	displayCircularQueue(CircularQueue *pQueue)
{
	int	idx;

	if (!pQueue || isCircularQueueEmpty(pQueue))
		return ;
	idx = pQueue->front;
	while (idx != pQueue->rear)
	{
		idx = (idx + 1) % pQueue->maxElementCount;
		printf("%c\n", pQueue->pElement[idx].data);
	}
}
