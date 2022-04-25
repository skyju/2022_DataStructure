#include "linkedStack.c"


int main(void) {
	LinkedStack *stack = NULL;

	//create
	stack = createLinkedStack(10);

	if (stack) {
		printf("----------------\n");
		printf("스택 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		//빈 stack display
		displayLinkedStack(stack);
		printf("\n\n");

		//push
		push(stack, 'a');
		push(stack, 'b');
		push(stack, 'c');
		push(stack, 'd');
		push(stack, 'e');
		push(stack, 'f');
		push(stack, 'g');
		printf("----------------\n");
		printf("7개 push\n");
		printf("----------------\n");
		printf("\n\n");

		//display
		displayLinkedStack(stack);
		printf("\n\n");

		//pop
		printf("----------------\n");
		printf("pop 3번\n");
		printf("----------------\n");
		pop(stack);
		pop(stack);
		pop(stack);
		
		//display
		displayLinkedStack(stack);
		printf("\n\n");
		
		printf("----------------\n");
		printf("7개 push\n");
		printf("----------------\n");
		push(stack, 'A');
		push(stack, 'B');
		push(stack, 'C');
		push(stack, 'D');
		push(stack, 'E');
		push(stack, 'F');
		push(stack, 'G');

		displayLinkedStack(stack);
		printf("\n\n");

		printf("----------------\n");
		printf("peek 3번\n");
		printf("1: %c\n", peek(stack));
		printf("2: %c\n", peek(stack));
		printf("3: %c\n", peek(stack));
		printf("----------------\n");

		displayLinkedStack(stack);
		printf("\n\n");

		//delete
		printf("----------------\n");
		printf("삭제 진행\n");
		printf("----------------\n");
		deleteLinkedStack(&stack);
		if (stack) {
			printf("삭제 안됨\n");
		} else {
			printf("삭제 완료\n");
		}
	}
}