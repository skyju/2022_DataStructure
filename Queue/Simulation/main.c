#include "simLinkedQueue.h"

int main(void)
{
	// insert 유효성
	// waiting time 오류

	int total_b_h; // total business hour 총 영업시간
	int currentTime; // 현재 시각
	int end_b_h; // 영업 종료시간 
	int check; // 고객을 입력받을지 안받을지 check
	int serviceTime; // 고객을 입력받을 시 고객의 서비스 타임
	int serviceUserCount = 0; // 총 고객 수
	int totalWaitTime = 0; // 총 고객의 기다림 시간 합
	int customerNumber = 1; // 번호표

	// 총 영업시간
	printf("Setting total business hours.\n");
	scanf("%d", &total_b_h);

	// 현재 시각
	printf("Setting current time.\n");
	scanf("%d", &currentTime);

	// 영업 종료시간 계산
	end_b_h = currentTime + total_b_h;

	LinkedQueue *pArrivalQueue;
	LinkedQueue *pWaitQueue;
	LinkedQueueNode *pServiceNode;
	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	pServiceNode = NULL;

	while (currentTime < end_b_h)
	{
		printf("\n===================================\n");
		printf("[ Current Time is %d, remaining business time is %d ]\n", currentTime, end_b_h - currentTime);
		printf("--------------------------------\n");
		printf("If you would like to enter a new customer, please press 1 or another number.\n");
		printf("press number! : ");
		scanf("%d", &check);
		// 도착큐 && 대기큐는 만들어져있는 상태
		// 고객이 도착을 하면 도착큐에 insert를 할건데..
		// insert하기전에 insert할 수 있는 상황인지 먼저 확인하고 (service time이 영업종료 시간을 넘어가는 지)
		if (check == 1)
		{
			if (pServiceNode && pServiceNode->data.endTime >= end_b_h)
				printf("Sorry. Today's service queue is full.\n");
			else
			{
				printf("Please enter the required service time.\n");
				printf("press number! : ");
				scanf("%d", &serviceTime);
				// 총 대기 인원들의 모든 서비스 시간을 다 더해서 .. 체크해야될 것 같아요..
				if ((currentTime + serviceTime >= end_b_h)
					|| (pServiceNode != NULL && pServiceNode->data.endTime + serviceTime >= end_b_h))
					printf("Sorry. It is outside of today's business hours.\n");
				else
				{
					// 집어 넣을 수 있는 상황일 때 도착큐에 insert
					if (serviceTime != 0)
					{
						insertCustomer(currentTime, serviceTime, customerNumber, pArrivalQueue);
						customerNumber += 1;
					}
					else
						printf("[error] Invalid Time.\n");
				}
			}
		}
		// 도착큐에 뭐가 있으면 대기큐로 집어넣어요.
		if (pArrivalQueue->front != NULL)
			processArrival(currentTime, pArrivalQueue, pWaitQueue);

		// 서비스중인 상태인데, 서비스 종료시간이 현재시각과 같으면, 서비스를 종료시켜줘야해요.
		if (pServiceNode && (pServiceNode->data.endTime - currentTime == 0))
		{
			pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
			printf("[ %dnd customer service end. ]\n", pServiceNode->data.customerNumber);
			free(pServiceNode);
			pServiceNode = NULL;
		}
		if (pServiceNode == NULL && pWaitQueue->front != NULL)
		{
			pServiceNode = processServiceNodeStart(currentTime, pWaitQueue); //startTime endTime 계산
			printf("[ %dnd customer service start! ]\n", pServiceNode->data.customerNumber);
		}

		// 대기중인 사람 출력
		if (pWaitQueue)
		{
			printf("--------------------------------\n");
			printWaitQueueStatus(currentTime, pWaitQueue);
		}

		// 서비스 상태를 출력
		printf("--------------------------------\n");
		if (pServiceNode != NULL)
		{
			printf("The %dth customer is using the service.\n", pServiceNode->data.customerNumber);
			printf("Remaining time is %d.\n", pServiceNode->data.endTime - currentTime);
		}
		else
			printf("There are no customers using the service.\n");
		++currentTime;
	}

	// 영업 종료 후, 총 고객 수와 총 웨이팅 타임 출력
	printReport(pWaitQueue, serviceUserCount, totalWaitTime, currentTime);
	deleteLinkedQueue(pWaitQueue);
	deleteLinkedQueue(pArrivalQueue);
	return (0);
}