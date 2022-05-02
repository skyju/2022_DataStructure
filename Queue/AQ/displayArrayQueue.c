#include <stdio.h>
#include "arrayqueue.h"

void	displayArrayQueue(ArrayQueue *pQueue)
{
	int	idx;

	if (!pQueue || isArrayQueueEmpty(pQueue))
		return ;
	idx = pQueue->front + 1;
	while (idx <= pQueue->rear)
	{
		printf("%c\n", pQueue->pElement[idx].data);
		idx++;
	}
}
