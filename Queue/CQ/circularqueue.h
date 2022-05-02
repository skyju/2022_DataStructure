#ifndef _CIRCULAR_QUEUE_
#define _CIRCULAR_QUEUE_

typedef struct CircularQueueNodeType
{
	char data;
} CircularQueueNode;

typedef struct CircularQueueType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	int front;					// front ��ġ
	int rear;					// rear ��ġ
	CircularQueueNode *pElement;	// ��� ������ ���� 1���� �迭 ������
} CircularQueue;

CircularQueue* createCircularQueue(int maxElementCount);
int enqueueCQ(CircularQueue* pQueue, CircularQueueNode element);
CircularQueueNode *dequeueCQ(CircularQueue* pQueue);
CircularQueueNode *peekCQ(CircularQueue* pQueue);
void deleteCircularQueue(CircularQueue* pQueue);
int isCircularQueueFull(CircularQueue* pQueue);
int isCircularQueueEmpty(CircularQueue* pQueue);
void displayCircularQueue(CircularQueue *pQueue);
void displayQueue(CircularQueue *pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
