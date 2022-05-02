#include "linkeddeque.h"

DequeNode *peekFrontLD(LinkedDeque *pDeque)
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
	return (pDeque->pFrontNode);
}
