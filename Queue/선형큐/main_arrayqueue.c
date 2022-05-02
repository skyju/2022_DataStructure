#include "arrayqueue.c"


int main(void) {
	ArrayQueue *queue = NULL;

	//create
	queue = createArrayQueue(10);

	if (queue) {
		printf("----------------\n");
		printf("큐 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		//빈 queue display
		displayArrayQueue(queue);
		printf("\n\n");

		//enqueue
		ArrayQueueNode node;
		node.data = 'a';
		enqueueAQ(queue, node);
		node.data = 'b';
		enqueueAQ(queue, node);
		node.data = 'c';
		enqueueAQ(queue, node);
		node.data = 'd';
		enqueueAQ(queue, node);
		node.data = 'e';
		enqueueAQ(queue, node);
		node.data = 'f';
		enqueueAQ(queue, node);
		node.data = 'g';
		enqueueAQ(queue, node);
		node.data = 'h';
		enqueueAQ(queue, node);
		printf("----------------\n");
		printf("8 enqueue finished..\n");
		printf("----------------\n");
		printf("\n\n");

		//queue display
		displayArrayQueue(queue);
		printf("\n\n");

		//dequeue
		printf("----------------\n");
		printf("dequeue 3번\n");
		printf("----------------\n");
		printf("1. : %c\n", dequeueAQ(queue)->data);
		printf("2. : %c\n", dequeueAQ(queue)->data);
		printf("3. : %c\n", dequeueAQ(queue)->data);
		printf("\n\n");
		
		//queue display
		displayArrayQueue(queue);
		printf("\n\n");

		printf("---reposition---\n");
		repositionAQ(queue);
		displayArrayQueue(queue);
		printf("\n\n");
		
		printf("----------------\n");
		printf("6개 enqueue\n");
		printf("----------------\n");
		node.data = 'A';
		enqueueAQ(queue, node);
		node.data = 'B';
		enqueueAQ(queue, node);
		node.data = 'C';
		enqueueAQ(queue, node);
		node.data = 'D';
		enqueueAQ(queue, node);
		node.data = 'E';
		enqueueAQ(queue, node);
		node.data = 'F';
		enqueueAQ(queue, node);

		//queue display
		displayArrayQueue(queue);
		printf("\n\n");

		printf("----------------\n");
		printf("peek 3번\n");
		printf("1. : %c\n", peekAQ(queue)->data);
		printf("2. : %c\n", peekAQ(queue)->data);
		printf("3. : %c\n", peekAQ(queue)->data);
		printf("----------------\n");

		//queue display
		displayArrayQueue(queue);
		printf("\n\n");

		//delete
		printf("----------------\n");
		printf("삭제 진행\n");
		printf("----------------\n");
		deleteArrayQueue(&queue);
		if (queue) {
			printf("삭제 안됨\n");
		} else {
			printf("삭제 완료\n");
		}
	}
}