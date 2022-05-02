#include "linkeddeque.h"

void deleteLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode *node;
	DequeNode *temp;

	if (!pDeque)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	node = pDeque->pFrontNode;
	while (node)
	{
		temp = node->pRLink;
		free(node);
		node = temp;
	}
	free(pDeque);
	pDeque = NULL;
}
