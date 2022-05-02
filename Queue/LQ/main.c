#include "linkedqueue.h"

/*
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
*/

enum e_input
{
	INPUT_NONE,
	INPUT_ENQUE,
	INPUT_DEQUE,
	INPUT_PEEK,
	INPUT_QUIT
};

int displayinput(LinkedQueue *pQueue)
{
	int input;
	int i;

	system("clear");
	printf("1. enque\n");
	printf("2. deque\n");
	printf("3. peek\n");
	printf("4. quit\n");
	printf("currentCount : %d\n", pQueue->currentElementCount);
	printf("(f)\n");
	displayLinkedQueue(pQueue);
	printf("(r)");
	printf("\n숫자를 입력해주세요.\n");

	scanf("%d", &input);

	return (input);
}

int main(void)
{
	int input;
	LinkedQueue *queue;
	LinkedQueueNode element;
	char tmp;

	system("clear");
	queue = createLinkedQueue();
	while (1)
	{
		input = 0;
		input = displayinput(queue);

		if (input == INPUT_QUIT)
			break;
		switch (input)
		{
		case INPUT_ENQUE:
			system("clear");
			printf("enqueue 할 문자를 입력해주세요. : ");
			scanf(" %c", &element.data);
			enqueueLQ(queue, element);
			break;
		case INPUT_DEQUE:
			dequeueLQ(queue);
			break;
		case INPUT_PEEK:
			if (peekLQ(queue))
				printf("%c\n", peekLQ(queue)->data);
			printf("press any character.\n");
			scanf(" %c", &tmp);
			break;
		}
	}
	deleteLinkedQueue(queue);
	return (0);
}

