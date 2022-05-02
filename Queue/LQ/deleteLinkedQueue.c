#include <stdlib.h>
#include "linkedqueue.h"

void	deleteLinkedQueue(LinkedQueue *pQueue)
{
	LinkedQueueNode	*Node;
	LinkedQueueNode	*temp;

	if (!pQueue)
		return ;
	Node = pQueue->front;
	while (Node)
	{
		temp = Node->pLink;
		free(Node);
		Node = temp;
	}
	free(pQueue);
}
