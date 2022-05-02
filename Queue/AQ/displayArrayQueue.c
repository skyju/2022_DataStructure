#include "arrayqueue.h"

void displayArrayQueue(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if (isArrayQueueEmpty(pQueue))
	{
		printf("Queue is empty.. \n");
		return;
	}
	int start = pQueue->front + 1;
	int end = pQueue->rear;
	for (int i = 0; i < start; i++)
		printf("[%d] : empty!..\n", i);
	for (int i = start; i <= end; i++)
		printf("[%d] : %c\n", i, pQueue->pElement[i].data);
}
