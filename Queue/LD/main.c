#include <stdio.h>
#include <stdlib.h>
#include "linkeddeque.h"

/*
int	main(void)
{
	LinkedDeque	*deque;
	DequeNode	element;

	deque = createLinkedDeque();

	element.data = 'A';
	insertFrontLD(deque, element);
	element.data = 'B';
	insertFrontLD(deque, element);
	
	printf("--- Front ---\n");
	displayFrontLinkedDeque(deque);
	printf("--- Rear ---\n");
	displayRearLinkedDeque(deque);

	element.data = 'Y';
	insertFrontLD(deque, element);
	element.data = 'Z';
	insertFrontLD(deque, element);
	
	printf("--- Front ---\n");
	displayFrontLinkedDeque(deque);
	printf("--- Rear ---\n");
	displayRearLinkedDeque(deque);

	deleteFrontLD(deque);
	printf("--- Front ---\n");
	displayFrontLinkedDeque(deque);
	printf("--- Rear ---\n");
	displayRearLinkedDeque(deque);
	deleteRearLD(deque);
	printf("--- Front ---\n");
	displayFrontLinkedDeque(deque);
	printf("--- Rear ---\n");
	displayRearLinkedDeque(deque);
	deleteLinkedDeque(deque);
	system("leaks a.out");
	return (0);
}
*/

enum	e_input
{
	INPUT_NONE,
	INPUT_ENQUEFRONT,
	INPUT_ENQUEREAR,
	INPUT_DEQUEFRONT,
	INPUT_DEQUEREAR,
	INPUT_DISPLAYFRONT,
	INPUT_DISPLAYREAR,
	INPUT_PEEKFRONT,
	INPUT_PEEKREAR,
	INPUT_QUIT
};

int	displayinput(LinkedDeque *pQueue)
{
	int	input;

	system("clear");
	printf("1. enqueFront\n");
	printf("2. enqueRear\n");
	printf("3. dequeFront\n");
	printf("4. dequeRear\n");
	printf("5. displayFront\n");
	printf("6. displayRear\n");
	printf("7. peekFront\n");
	printf("8. peekRear\n");
	printf("9. quit\n");
	printf("currentCount : %d\n", pQueue->currentElementCount);
	displayLinkedDeque(pQueue);
	printf("\n숫자를 입력해주세요.\n");

	scanf("%d", &input);

	return (input);
}

int	main(void)
{	
	int					input;
	LinkedDeque		*deque;
	DequeNode		*peek;
	DequeNode		element;

	deque = createLinkedDeque();
	while (1)
	{
		input = displayinput(deque);

		if (input == INPUT_QUIT)
			break ;
		switch (input)
		{
		case INPUT_ENQUEFRONT:
			system("clear");
			printf("enqueue 할 문자를 입력해주세요. : ");
			scanf(" %c", &element.data);
			insertFrontLD(deque, element);
			break ;
		case INPUT_ENQUEREAR:
			system("clear");
			printf("enqueue 할 문자를 입력해주세요. : ");
			scanf(" %c", &element.data);
			insertRearLD(deque, element);
			break ;
		case INPUT_DEQUEFRONT:
			deleteFrontLD(deque);
			break ;
		case INPUT_DEQUEREAR:
			deleteRearLD(deque);
			break ;
		case INPUT_DISPLAYFRONT:
			displayFrontLinkedDeque(deque);
			system("read -n 1 -s -p \"Press any key for return\"");
			break ;
		case INPUT_DISPLAYREAR:
			displayRearLinkedDeque(deque);
			system("read -n 1 -s -p \"Press any key for return\"");
			break ;
		case INPUT_PEEKFRONT:
			peek = peekFrontLD(deque);
			printf("\npeekFrontNode : %c\n", peek->data);
			system("read -n 1 -s -p \"Press any key for return\"");
			break ;
		case INPUT_PEEKREAR:
			peek = peekRearLD(deque);
			printf("\npeekRearNode : %c\n", peek->data);
			system("read -n 1 -s -p \"Press any key for return\"");
			break ;
		}
	}
	deleteLinkedDeque(deque);
	return (0);
}
