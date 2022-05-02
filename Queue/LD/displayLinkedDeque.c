#include "linkeddeque.h"

void displayLinkedDeque(LinkedDeque *pDeque)
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
		printf("%c ", node->data);
		node = temp;
	}
}
