#include "linkeddeque.h"

DequeNode	*peekFrontLD(LinkedDeque *pDeque)
{
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (FALSE);
	return (pDeque->pFrontNode);
}
