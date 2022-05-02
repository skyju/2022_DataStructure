#include "linkeddeque.h"

void displayRearLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode *node;
	DequeNode *temp;

	if (!pDeque)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	node = pDeque->pRearNode;
	while (node)
	{
		temp = node->pLLink;
		printf("%c\n", node->data);
		node = temp;
	}
}
