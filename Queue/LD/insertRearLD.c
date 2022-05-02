#include "linkeddeque.h"

int insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
	DequeNode *node;

	if (!pDeque)
	{
		printf("[error] Queue is null.\n");
		return (ERROR);
	}
	node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!node)
	{
		printf("[error] Memory allocate failed.\n");
		return (ERROR);
	}
	*node = element;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
		node->pLLink = NULL;
		node->pRLink = NULL;
	}
	else
	{
		pDeque->pRearNode->pRLink = node;
		node->pLLink = pDeque->pRearNode;
		node->pRLink = NULL;
		pDeque->pRearNode = node;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
