#include "linkeddeque.h"

int insertFrontLD(LinkedDeque *pDeque, DequeNode element)
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
		pDeque->pFrontNode->pLLink = node;
		node->pRLink = pDeque->pFrontNode;
		node->pLLink = NULL;
		pDeque->pFrontNode = node;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
