#include <stdlib.h>
#include "circularqueue.h"

void	deleteCircularQueue(CircularQueue *pQueue)
{
	if (!pQueue)
		return ;
	free(pQueue->pElement);
	free(pQueue);
	pQueue = 0;
}
