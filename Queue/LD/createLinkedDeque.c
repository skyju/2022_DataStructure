#include "linkeddeque.h"

LinkedDeque *createLinkedDeque(void)
{
	LinkedDeque *Deque;

	Deque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!Deque)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	Deque->currentElementCount = 0;
	Deque->pFrontNode = 0;
	Deque->pRearNode = 0;
	return (Deque);
}
