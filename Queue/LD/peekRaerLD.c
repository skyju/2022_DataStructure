#include "linkeddeque.h"

DequeNode	*peekRearLD(LinkedDeque *pDeque)
{
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (FALSE);
	return (pDeque->pRearNode);
}
