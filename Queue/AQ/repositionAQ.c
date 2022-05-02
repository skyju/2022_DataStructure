#include "arrayqueue.h"

int repositionAQ(ArrayQueue *pQueue)
{
	ArrayQueueNode *tmp;
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}
	if (isArrayQueueEmpty(pQueue))
		return (FALSE);
	int i;
	int cnt = pQueue->currentElementCount;
	for (i = 0; i < cnt; i++)
	{
		tmp = dequeueAQ(pQueue);
		pQueue->pElement[i] = *tmp;
		free(tmp);
	}
	pQueue->front = -1;
	pQueue->rear = i - 1;
	pQueue->currentElementCount = cnt;
	return (TRUE);
}