#include <stdlib.h>
#include "linkeddeque.h"

DequeNode	*deleteRearLD(LinkedDeque *pDeque)
{
	DequeNode	*Node;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (0);
	Node = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	Node->pLLink = 0;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
	}
	else
	{
		pDeque->pRearNode->pRLink = 0;
	}
	free(Node);
	pDeque->currentElementCount--;
	return (Node);
}
