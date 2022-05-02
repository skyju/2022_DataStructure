#include <stdlib.h>
#include "linkeddeque.h"

int	insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
	DequeNode	*Node;

	if (!pDeque)
		return (ERROR);
	Node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!Node)
		return (ERROR);
	Node->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = Node;
		pDeque->pRearNode = Node;
	}
	else
	{
		pDeque->pRearNode->pRLink = Node;
		Node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = Node;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
