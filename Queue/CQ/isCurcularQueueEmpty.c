#include "circularqueue.h"

int isCircularQueueEmpty(CircularQueue *pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
