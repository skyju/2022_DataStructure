#include "linkeddeque.h"

void displayFrontLinkedDeque(LinkedDeque *pDeque)
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
		printf("%c\n", node->data);
		node = temp;
	}
}
