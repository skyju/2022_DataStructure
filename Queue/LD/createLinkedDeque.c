#include <stdlib.h>
#include "linkeddeque.h"

LinkedDeque	*createLinkedDeque(void)
{
	LinkedDeque	*Deque;

	Deque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!Deque)
		return (FALSE);
	Deque->currentElementCount = 0;
	Deque->pFrontNode = 0;
	Deque->pRearNode = 0;
	return (Deque);
}
