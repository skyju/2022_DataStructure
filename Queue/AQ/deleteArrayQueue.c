#include "arrayqueue.h"

void deleteArrayQueue(ArrayQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if (pQueue->pElement)
		free(pQueue->pElement);
	free(pQueue);
	pQueue = NULL;
}

/*
void deleteArrayQueue(ArrayQueue **pQueue)
{
	if (*pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if ((*pQueue)->arr != NULL)
		free((*pQueue)->arr);
	free(*pQueue);
	*pQueue = NULL;
}
*/