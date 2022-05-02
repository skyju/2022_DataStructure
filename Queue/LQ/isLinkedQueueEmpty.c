#include "linkedqueue.h"

int	isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	if (!pQueue)
		return (0);
	if (pQueue->currentElementCount == 0)
		return (1);
	return (0);
}
