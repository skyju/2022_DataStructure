#include <stdlib.h>
#include "linkeddeque.h"

DequeNode	*deleteFrontLD(LinkedDeque *pDeque)
{
	DequeNode	*Node;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (0);
	Node = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	Node->pRLink = 0;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pRearNode = 0;
	}
	else
	{
		pDeque->pFrontNode->pLLink = 0;
	}
	free(Node);
	pDeque->currentElementCount--;
	return (Node);
}
