#include "arrayqueue.h"

/*
int	main(void)
{
	ArrayQueue		*queue;
	ArrayQueueNode	*peek;
	ArrayQueueNode	*de;
	ArrayQueueNode	element;

	queue = createArrayQueue(4);

	printf("empty : %d \n", isArrayQueueEmpty(queue));

	element.data = 'A';
	enqueueAQ(queue, element);
	element.data = 'B';
	enqueueAQ(queue, element);
	element.data = 'C';
	enqueueAQ(queue, element);
	element.data = 'D';
	enqueueAQ(queue, element);
	printf("empty : %d \n", isArrayQueueEmpty(queue));
	printf("full : %d \n", isArrayQueueFull(queue));

	displayArrayQueue(queue);
	de = dequeueAQ(queue);
	printf("de : %c\n", de->data);
	element.data = 'E';
	enqueueAQ(queue, element);
	displayArrayQueue(queue);
	printf("-- deque 'A' -- \n");
	displayArrayQueue(queue);
	peek = peekAQ(queue);
	printf("-- peek data %c ( result : 'B' ) --\n", peek->data);
	dequeueAQ(queue);
	printf("-- deque 'B' -- \n");
	displayArrayQueue(queue);
	dequeueAQ(queue);
	printf("-- deque 'C' -- \n");
	displayArrayQueue(queue);
	//de = dequeueAQ(queue);
	//printf("Underflow %c\n", de->data);
	displayArrayQueue(queue);
	printf("empty : %d \n", isArrayQueueEmpty(queue));
	printf("full : %d \n", isArrayQueueFull(queue));
	deleteArrayQueue(queue);
	system("leaks a.out");
	return (0);
}*/

enum e_input
{
	INPUT_NONE,
	INPUT_ENQUE,
	INPUT_DEQUE,
	INPUT_PEEK,
	INPUT_REPOSITION,
	INPUT_DISPLAY,
	INPUT_QUIT
};

int displayinput(ArrayQueue *pQueue)
{
	int input;
	int i;

	system("clear");
	printf("1. enque\n");
	printf("2. deque\n");
	printf("3. peek\n");
	printf("4. reposition\n");
	printf("5. display\n");
	printf("6. quit\n");
	printf("currentCount : %d, maxCount : %d\n", pQueue->currentElementCount, pQueue->maxElementCount);
	i = 0;
	while (i++ <= pQueue->front)
		printf(" ");
	printf("f\n");
	displayQueue(pQueue);
	i = 0;
	printf("\n");
	while (i++ <= pQueue->rear)
		printf(" ");
	printf("r");
	printf("\n숫자를 입력해주세요.\n");

	scanf("%d", &input);

	return (input);
}

int main(void)
{
	int input;
	ArrayQueue *queue;
	ArrayQueueNode element;
	char tmp;

	system("clear");
	printf("생성 할 배열의 크기를 입력해주세요. :");
	scanf("%d", &input);
	queue = createArrayQueue(input);
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
			enqueueAQ(queue, element);
			break;
		case INPUT_DEQUE:
			dequeueAQ(queue);
			break;
		case INPUT_PEEK:
			if (peekAQ(queue))
				printf("%c\n", peekAQ(queue)->data);
			printf("press any character.\n");
			scanf(" %c", &tmp);
			break;
		case INPUT_REPOSITION:
			repositionAQ(queue);
			break;
		case INPUT_DISPLAY:
			displayArrayQueue(queue);
			printf("press any character.\n");
			scanf(" %c", &tmp);
			// system("read -n 1 -s -p \"Press any key for return\"");
			break;
		}
	}
	deleteArrayQueue(queue);
	return (0);
}
