#include "arrayqueue.h"

void displayQueue(ArrayQueue *pQueue)
{
	int i;
	int idx;

	if (!pQueue || isArrayQueueEmpty(pQueue))
		return;
	idx = pQueue->front + 1;
	i = 0;
	while (i++ <= pQueue->front)
		printf(" ");
	while (idx <= pQueue->rear)
	{
		printf("%c", pQueue->pElement[idx].data);
		idx++;
	}
}
