#include "circularqueue.h"
/*
int	main(void)
{
	CircularQueue		*queue;
	CircularQueueNode	*de;
	CircularQueueNode	*peek;
	CircularQueueNode	element;

	queue = createCircularQueue(4);
	element.data = 'A';
	enqueueCQ(queue, element);
	element.data = 'B';
	enqueueCQ(queue, element);
	element.data = 'C';
	enqueueCQ(queue, element);
	element.data = 'D';
	enqueueCQ(queue, element);
//	displayCircularQueue(queue);
//	dequeueCQ(queue);
//	peek = peekCQ(queue);
//	printf("peek : %c\n", peek->data);
//	element.data = 'E';
//	enqueueCQ(queue, element);
//	element.data = 'F';
//	enqueueCQ(queue, element);
//	dequeueCQ(queue);
//	element.data = 'G';
//	enqueueCQ(queue, element);
	displayCircularQueue(queue);
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

int displayinput(CircularQueue *pQueue)
{
	int input;

	system("clear");
	printf("1. enque\n");
	printf("2. deque\n");
	printf("3. peek\n");
	printf("4. quit\n");
	printf("currentCount : %d, maxCount : %d\n", pQueue->currentElementCount, pQueue->maxElementCount);
	displayCircularQueue(pQueue);
	printf("\n숫자를 입력해주세요.\n");

	scanf("%d", &input);

	return (input);
}

int main(void)
{
	int input;
	CircularQueue *queue;
	CircularQueueNode element;
	char tmp;

	system("clear");
	printf("생성 할 배열의 크기를 입력해주세요. :");
	scanf("%d", &input);
	queue = createCircularQueue(input);
	while (1)
	{
		input = displayinput(queue);

		if (input == INPUT_QUIT)
			break;
		switch (input)
		{
		case INPUT_ENQUE:
			system("clear");
			printf("enqueue 할 문자를 입력해주세요. : ");
			scanf(" %c", &element.data);
			enqueueCQ(queue, element);
			break;
		case INPUT_DEQUE:
			dequeueCQ(queue);
			break;
		case INPUT_PEEK:
			if (peekCQ(queue))
				printf("%c\n", peekCQ(queue)->data);
			printf("press any character.\n");
			scanf(" %c", &tmp);
			break;
		}
	}
	deleteCircularQueue(queue);
	return (0);
}
