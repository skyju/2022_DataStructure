#include <stdio.h>
#include "linkeddeque.h"

void	displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*Node;
	DequeNode	*temp;

	Node = pDeque->pFrontNode;
	while (Node)
	{
		temp = Node->pRLink;
		printf("%c ", Node->data);
		Node = temp;
	}
}
