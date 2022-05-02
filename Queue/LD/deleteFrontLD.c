#include "linkeddeque.h"

DequeNode *deleteFrontLD(LinkedDeque *pDeque)
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

	DequeNode *node;
	node = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	node->pRLink = NULL;
	if (pDeque->currentElementCount == 1)
		pDeque->pRearNode = NULL;
	else
		pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	return (node);
}
