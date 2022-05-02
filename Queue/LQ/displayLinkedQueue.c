#include "linkedqueue.h"

void displayLinkedQueue(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("Queue is empty.. \n");
		return;
	}
	LinkedQueueNode *cur;

	cur = pQueue->front;
	while (cur)
	{
		printf("%c\n", cur->data);
		cur = cur->pLink;
	}
}
