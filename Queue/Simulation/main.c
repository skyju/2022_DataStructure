#include "simLinkedQueue.h"

int main(void)
{
	int total_b_h;
	int currentTime;
	int end_b_h;
	int check;
	int serviceTime;
	int serviceUserCount = 0;
	int totalWaitTime = 0;
	int customerNumber = 1;

	printf("Setting total business hours.\n");
	scanf("%d", &total_b_h);

	printf("Setting current time.\n");
	scanf("%d", &currentTime);

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
		if (check == 1)
		{
			if (pServiceNode && pServiceNode->data.endTime >= end_b_h)
				printf("Sorry. Today's service queue is full.\n");
			else
			{
				printf("Please enter the required service time.\n");
				printf("press number! : ");
				scanf("%d", &serviceTime);
				if ((currentTime + serviceTime >= end_b_h)
					|| (pServiceNode != NULL && pServiceNode->data.endTime + serviceTime >= end_b_h))
					printf("Sorry. It is outside of today's business hours.\n");
				else
				{
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
		if (pArrivalQueue->front != NULL)
			processArrival(currentTime, pArrivalQueue, pWaitQueue);
		if (pServiceNode && (pServiceNode->data.endTime - currentTime == 0))
		{
			pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
			printf("[ %dnd customer service end. ]\n", pServiceNode->data.customerNumber);
			free(pServiceNode);
			pServiceNode = NULL;
		}
		if (pServiceNode == NULL && pWaitQueue->front != NULL)
		{
			pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
			printf("[ %dnd customer service start! ]\n", pServiceNode->data.customerNumber);
		}
		if (pWaitQueue)
		{
			printf("--------------------------------\n");
			printWaitQueueStatus(currentTime, pWaitQueue);
		}
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
	printReport(pWaitQueue, serviceUserCount, totalWaitTime, currentTime);
	deleteLinkedQueue(pWaitQueue);
	deleteLinkedQueue(pArrivalQueue);
	return (0);
}