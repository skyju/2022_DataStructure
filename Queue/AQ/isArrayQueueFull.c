#include "arrayqueue.h"

int	isArrayQueueFull(ArrayQueue *pQueue)
{
	if (pQueue->currentElementCount == pQueue->maxElementCount
		|| pQueue->rear == pQueue->maxElementCount - 1)
		return (TRUE);
	return (FALSE);
}
