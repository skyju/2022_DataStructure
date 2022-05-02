#include <stdlib.h>
#include "linkeddeque.h"

int	insertFrontLD(LinkedDeque *pDeque, DequeNode element)
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
		pDeque->pFrontNode->pLLink = Node;
		Node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = Node;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
