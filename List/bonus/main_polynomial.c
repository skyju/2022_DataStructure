#include "polynomial.h"
#include "polynomial.c"

int main(void)
{
	PolyList *a = NULL;
	PolyList *b = NULL;
	PolyList *c = NULL;

	a = createPolyList();
	b = createPolyList();

	if (a != NULL && b != NULL)
	{
		addPolyNodeLast(a, 7, 6);
		addPolyNodeLast(a, 3, 5);
		addPolyNodeLast(a, 5, 2);
		addPolyNodeLast(a, 12, 7);
		addPolyNodeLast(a, 4, 0);
		addPolyNodeLast(a, 2, 4);
		printf("a list!\n");
		displayPolyList(a);
		printf("\n\n");

		addPolyNodeLast(b, 1, 5);
		addPolyNodeLast(b, 2, 4);
		addPolyNodeLast(b, 3, 2);
		addPolyNodeLast(b, 2, 7);
		printf("b list!\n");
		displayPolyList(b);
		printf("\n\n");

		c = polyAddCal(a, b);
		displayPolyList(c);
	}
}