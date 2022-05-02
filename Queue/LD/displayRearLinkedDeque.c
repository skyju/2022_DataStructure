#include <stdio.h>
#include "linkeddeque.h"

void	displayRearLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*Node;
	DequeNode	*temp;

	Node = pDeque->pRearNode;
	while (Node)
	{
		temp = Node->pLLink;
		printf("%c\n", Node->data);
		Node = temp;
	}
}
