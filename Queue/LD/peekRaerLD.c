#include "linkeddeque.h"

DequeNode *peekRearLD(LinkedDeque *pDeque)
{
	if (!pDeque)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	return (pDeque->pRearNode);
}
