#include "arrayqueue.h"

// 1. 큐 생성
ArrayQueue *createArrayQueue(int maxCount)
{
	ArrayQueue *result;
	result = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
	if (result == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	result->maxCount = maxCount;
	result->currentCount = 0;
	result->front = -1;
	result->rear = -1;
	result->arr = (ArrayQueueNode *)calloc(maxCount, sizeof(ArrayQueueNode));
	if (result->arr == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		free(result);
		return (NULL);
	}
	return (result);
}

int isArrayQueueFull(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (TRUE);
	}
	if (pQueue->currentCount == pQueue->maxCount || pQueue->rear == pQueue->maxCount - 1)
		return (TRUE);
	return (FALSE);
}

// 2. 인큐 연산
// 리어 노드를 이동하는데 mod연산자 사용
// rear = (rear + 1) % maxCount; 
// (배열의 크기보다 커지면 한바퀴 돌아오는 걸 상상)
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}
	if (isArrayQueueFull(pQueue))
	{
		printf("[error] Queue is already full.\n");
		return (FALSE);
	}
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxCount;
	pQueue->arr[pQueue->rear] = element;
	pQueue->currentCount++;
	return (TRUE);
}

int isArrayQueueEmpty(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (TRUE);
	}
	if (pQueue->currentCount == 0)
		return (TRUE);
	return (FALSE);
}

// 3. 디큐 연산
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isArrayQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}

	ArrayQueueNode *result;
	result = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (result == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	
	pQueue->front = (pQueue->front + 1) % pQueue->maxCount;
	*result = pQueue->arr[pQueue->front];
	pQueue->arr[pQueue->front].data = 0;
	pQueue->currentCount--;
	return (result);
}

// 4. 피크 연산
ArrayQueueNode *peekAQ(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isArrayQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	return (&(pQueue->arr[pQueue->front + 1]));
}

// 5. 큐 삭제
void deleteArrayQueue(ArrayQueue **pQueue)
{
	if (*pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if ((*pQueue)->arr != NULL)
		free((*pQueue)->arr);
	free(*pQueue);
	*pQueue = NULL;
}

// 6. 큐 정보 조회
void displayArrayQueue(ArrayQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}
	if (isArrayQueueEmpty(pQueue))
	{
		printf("Queue is empty.. \n");
		return;
	}
	int start = pQueue->front + 1;
	int end = pQueue->rear;
	for (int i = 0; i < start; i++)
		printf("[%d] : empty!..\n", i);
	for (int i = start; i <= end; i++)
		printf("[%d] : %c\n", i, pQueue->arr[i].data);
}