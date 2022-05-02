#include "arrayqueue.h"

int isArrayQueueEmpty(ArrayQueue *pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
