#include "linkedqueue.h"

LinkedQueueNode *peekLQ(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	return (pQueue->front);
}
