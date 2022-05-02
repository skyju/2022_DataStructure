#include "linkeddeque.h"

DequeNode *deleteRearLD(LinkedDeque *pDeque)
{
	if (!pDeque)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("[error] Queue is empty.\n");
	}

	DequeNode *node;
	node = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	node->pLLink = NULL;
	if (pDeque->currentElementCount == 1)
		pDeque->pFrontNode = NULL;
	else
		pDeque->pRearNode->pRLink = NULL;
	pDeque->currentElementCount--;
	return (node);
}
