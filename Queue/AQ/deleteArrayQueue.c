#include <stdlib.h>
#include "arrayqueue.h"

void	deleteArrayQueue(ArrayQueue *pQueue)
{
	if (!pQueue)
		return ;
	free(pQueue->pElement);
	free(pQueue);
}
