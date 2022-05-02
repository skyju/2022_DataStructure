#include "linkedqueue.h"

LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue)
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
	LinkedQueueNode *node;
	node = pQueue->front;
	pQueue->front = pQueue->front->pLink;
	node->pLink = NULL;
	if (pQueue->currentElementCount == 1) //노드가 한개일 때는 리어 처리도 해야 함
		pQueue->rear = NULL;
	pQueue->currentElementCount--;
	return (node);
}
