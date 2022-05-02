#include <stdio.h>
#include "linkeddeque.h"

void	displayFrontLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*Node;
	DequeNode	*temp;

	Node = pDeque->pFrontNode;
	while (Node)
	{
		temp = Node->pRLink;
		printf("%c\n", Node->data);
		Node = temp;
	}
}
