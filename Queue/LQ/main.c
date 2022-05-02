#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

int	main(void)
{
	LinkedQueue	*queue;
	LinkedQueueNode	*de;
	LinkedQueueNode	*peek;
	LinkedQueueNode element;

	queue = createLinkedQueue();
	element.data = 'A';
	enqueueLQ(queue, element);
	element.data = 'B';
	enqueueLQ(queue, element);
	element.data = 'C';
	enqueueLQ(queue, element);
	element.data = 'D';
	enqueueLQ(queue, element);
	displayLinkedQueue(queue);
	dequeueLQ(queue);
	peek = peekLQ(queue);
	printf("%c\n", peek->data);
	dequeueLQ(queue);
	peek = peekLQ(queue);
	printf("%c\n", peek->data);
	printf("----- display -----\n");
	displayLinkedQueue(queue);
	deleteLinkedQueue(queue);
	system("leaks a.out");
	return (0);
}
