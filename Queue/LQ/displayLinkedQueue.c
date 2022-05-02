#include <stdio.h>
#include "linkedqueue.h"

void	displayLinkedQueue(LinkedQueue *pQueue)
{
	LinkedQueueNode	*cur;

	if (!pQueue)
		return ;
	cur = pQueue->front;
	while (cur)
	{
		printf("%c\n", cur->data);
		cur = cur->pLink;
	}
}
