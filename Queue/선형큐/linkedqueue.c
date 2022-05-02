#include "linkedqueue.h"

// 1. 큐 생성
LinkedQueue *createLinkedQueue()
{
	LinkedQueue *result;
	result = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (result == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	result->count = 0;
	result->front = NULL;
	result->rear = NULL;
	return (result);
}

int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (2);
	}
	if (pQueue->count == 0)
		return (TRUE);
	return (FALSE);
}

// 2. 인큐 연산
int enqueueLQ(LinkedQueue *pQueue, LinkedQueueNode element)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}

	LinkedQueueNode *new_Node;
	new_Node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	if (new_Node == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (FALSE);
	}

	*new_Node = element;
	new_Node->next = NULL;

	if (isLinkedQueueEmpty(pQueue) == 1) // 빈큐일때
	{
		pQueue->front = new_Node;
		pQueue->rear = new_Node;
	}
	else
	{
		pQueue->rear->next = new_Node;
		pQueue->rear = new_Node;
	}
	pQueue->count++;
	return (TRUE);
}

// 3. 디큐 연산
LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}

	LinkedQueueNode *result;
	result = pQueue->front;
	pQueue->front = pQueue->front->next;
	result->next = NULL;
	if (pQueue->count == 1) //노드가 한개일 때는 리어 처리도 해야 함
	{
		pQueue->rear = NULL;
	}
	pQueue->count--;
	return (result);
}

// 4. 피크 연산
LinkedQueueNode *peekLQ(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	return (pQueue->front);
}

// 5. 큐 삭제
void deleteLinkedQueue(LinkedQueue **pQueue)
{
	if (*pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	LinkedQueueNode *tmp;
	LinkedQueueNode *delete_tmp;
	tmp = (*pQueue)->front;
	while (tmp != NULL)
	{
		delete_tmp = tmp;
		tmp = tmp->next;
		free(delete_tmp);
	}
	free(*pQueue);
	*pQueue = NULL;
}

// 6. 큐 정보 조회
void displayLinkedQueue(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("Queue is empty.. \n");
		return;
	}
	printf("[display]\n");
	printf("count ? : %d\n", pQueue->count);
	int i = 0;
	for (LinkedQueueNode *tmp = pQueue->front; tmp != NULL; tmp = tmp->next)
		printf("[%d] : %c\n", i++, tmp->data);
}