#include "polynomial.h"

int main(void)
{
	PolyList *a = NULL;
	PolyList *b = NULL;
	PolyList *c = NULL;

	a = createPolyList();
	b = createPolyList();

	if (!a && !b)
	{
		addPolyListNodeLast(a, 7, 6);
		addPolyListNodeLast(a, 3, 5);
		addPolyListNodeLast(a, 5, 2);
		displayPolyList(a);

		addPolyListNodeLast(b, 1, 5);
		addPolyListNodeLast(b, 2, 4);
		addPolyListNodeLast(b, 3, 2);
		addPolyListNodeLast(b, 4, 0);
		displayPolyList(b);

		c = polyAddCal(a, b);
		displayPolyList(c);
	}
}