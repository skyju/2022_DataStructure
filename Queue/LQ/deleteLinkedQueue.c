#include "linkedqueue.h"

void deleteLinkedQueue(LinkedQueue *pQueue)
{
	LinkedQueueNode *node;
	LinkedQueueNode *temp;

	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	node = pQueue->front;
	while (node)
	{
		temp = node->pLink;
		free(node);
		node = temp;
	}
	free(pQueue);
	pQueue = NULL;
}

/*
void deleteLinkedQueue(LinkedQueue **pQueue)
{
	if (*pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	LinkedQueueNode *tmp;
	LinkedQueueNode *delete_tmp;
	tmp = (*pQueue)->front;
	while (tmp != NULL)
	{
		delete_tmp = tmp;
		tmp = tmp->pLink;
		free(delete_tmp);
	}
	free(*pQueue);
	*pQueue = NULL;
}
*/