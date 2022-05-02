#include "linkedqueue.c"


int main(void) {
	LinkedQueue *queue = NULL;

	//create
	queue = createLinkedQueue();

	if (queue) {
		printf("----------------\n");
		printf("큐 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		//빈 queue display
		displayLinkedQueue(queue);
		printf("\n\n");

		//enqueue
		LinkedQueueNode node;
		node.data = 'a';
		enqueueLQ(queue, node);
		node.data = 'b';
		enqueueLQ(queue, node);
		node.data = 'c';
		enqueueLQ(queue, node);
		printf("----------------\n");
		printf("3 enqueue finished..\n");
		printf("----------------\n");
		printf("\n\n");

		//queue display
		displayLinkedQueue(queue);
		printf("\n\n");

		//dequeue
		printf("----------------\n");
		printf("dequeue 3번\n");
		printf("----------------\n");
		printf("1. : %c\n", dequeueLQ(queue)->data);
		printf("2. : %c\n", dequeueLQ(queue)->data);
		printf("3. : %c\n", dequeueLQ(queue)->data);
		printf("\n\n");
		
		//queue display
		displayLinkedQueue(queue);
		printf("\n\n");
		
		printf("----------------\n");
		printf("6개 enqueue\n");
		printf("----------------\n");
		node.data = 'A';
		enqueueLQ(queue, node);
		node.data = 'B';
		enqueueLQ(queue, node);
		node.data = 'C';
		enqueueLQ(queue, node);
		node.data = 'D';
		enqueueLQ(queue, node);
		node.data = 'E';
		enqueueLQ(queue, node);
		node.data = 'F';
		enqueueLQ(queue, node);

		//queue display
		displayLinkedQueue(queue);
		printf("\n\n");

		printf("----------------\n");
		printf("peek 3번\n");
		printf("1. : %c\n", peekLQ(queue)->data);
		printf("2. : %c\n", peekLQ(queue)->data);
		printf("3. : %c\n", peekLQ(queue)->data);
		printf("----------------\n");

		//queue display
		displayLinkedQueue(queue);
		printf("\n\n");

		//delete
		printf("----------------\n");
		printf("삭제 진행\n");
		printf("----------------\n");
		deleteLinkedQueue(&queue);
		if (queue) {
			printf("삭제 안됨\n");
		} else {
			printf("삭제 완료\n");
		}
	}
}