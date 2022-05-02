#include <stdlib.h>
#include "linkeddeque.h"

void	deleteLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*Node;
	DequeNode	*temp;

	if (!pDeque)
		return ;
	Node = pDeque->pFrontNode;
	while (Node)
	{
		temp = Node->pRLink;
		free(Node);
		Node = temp;
	}
	free(pDeque);
}
