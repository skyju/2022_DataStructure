#include "circularList.h"

// 생성
CircularList *createCircularList()
{
	CircularList *result;

	result = (CircularList *)malloc(sizeof(CircularList));
	if (!result)
	{
		printf("[error : createCircularList] Memory allocation failed.\n");
		return (NULL);
	}

	result->currentCount = 0;
	result->head.next = result;
	return (result);
}

// 대체
int replaceCLElement(CircularList *list, int index, CircularListNode element)
{
	CircularListNode *tmp;

	if (list == NULL)
	{
		printf("[error : replaceCLElement] Circular is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount)
	{
		printf("[error : replaceCLElement] Invalid index.\n");
		return (FALSE);
	}

	tmp = &(list->head);
	for (int i = 0; i <= index; i++)
	{
		tmp = tmp->next;
	}
	tmp->data = element.data;

	return (TRUE);
}

// 원소 추가
int addCLElement(CircularList *list, int index, CircularListNode element)
{
	CircularListNode prev_Node;
	CircularListNode new_Node;

	if (list == NULL)
	{
		printf("[error : addCLElement] CirculrList is NULL.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentCount)
	{
		printf("[error : addCLElement] Invalid index\n");
		return (FALSE);
	}
	new_Node = (CircularListNode *)malloc(sizeof(CircularListNode *));
	if (!new_Node)
	{
		printf("[error : addCLElement] Memory allocation failed\n");
		return (FALSE);
	}

	// 이전 노드 찾기
	prev_Node = &(list->head);
	for (i = 0; i < index; i++)
		prev_Node = prev_Node->next;

	// 생성노드 할당 및 새로운 연결해주기
	*new_Node = element;
	new_Node->next = prev_Node->next;
	prev_Node->next = new_Node;

	// 맨 처음 노드가 추가된 경우, 다음 노드 자기자신으로 지정
	if (prev_Node->next == NULL)
		new_Node->next = new_Node;
	list->currentCount += 1;

	return (TRUE);
}

// 원소 삭제
int removeCLElement(CircularList *list, int index)
{
	CircularListNode prev_Node;
	CircularListNode del_Node;

	if (list == NULL)
	{
		printf("[error : removeCLElement] CircularList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentCount)
	{
		printf("[error : removeCLElement] Invalid index\n");
		return (FALSE);
	}

	// 노드 삭제 및 새로운 연결해주기
	prev_Node = &(list->head);
	if (index == 0)
	{
		list->head = *(prev_Node->next);
		free(prev_Node->next);
	}
	else
	{
		for (int i = 0; i < index; i++)
			prev_Node = prev_Node->next;
		del_Node = prev_Node->next;
		prev_Node->next = del_Node->next;
		free(del_Node);
	}

	// 마지막 남은 노드가 삭제된 경우 헤더 노드를 NULL로 지정
	if (list->currentCount == 0)
		list->head->next = NULL;

	list->currentCount -= 1;

	return (TRUE);
}

// 특정 인덱스 가져오기
CircularListNode *getCLElement(CircularList *list, int index)
{
	CircularListNode *result;

	if (list == NULL)
	{
		printf("[error : getCLElement] CircularList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentCount)
	{
		printf("[error : getCLElement] Invalid index\n");
		return (FALSE);
	}
	result = &(list->head);
	for (int i = 0; i <= index; i++)
		result = result->next;
	return (result);
}

// 정보 출력
void displayCircularList(CircularList *list)
{
	CircularListNode *tmp;

	if (list == NULL)
	{
		printf("[error : displayCircularList] CircularList is Null.\n");
		return;
	}
	printf("Current Element Count : %d\n", list->currentCount);
	printf("----[element display]----\n");
	tmp = &(list->head);
	for (int i = 0; i < list->currentElementCount; i++)
	{
		printf("[%d]'s element : %d\n", i, tmp->data);
		tmp = tmp->next;
	}
}

// 초기화
void clearCircularList(CircularList *list)
{
	CircularListNode *tmp;
	CircularListNode *tmp2;

	if (list == NULL)
	{
		printf("[error : clearCircularList] CircularList is Null.\n");
		return;
	}
	tmp = &(list->head);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp;
		free(tmp2->next);
	}
	list->currentCount = 0;
}

// 길이
int getCircularListLength(CircularList *list)
{
	if (list == NULL)
	{
		printf("[error : getCircularListLength] CircularList is Null.\n");
		return (FALSE);
	}
	return (list->currentCount);
}

// 삭제
void deleteCircularList(CircularList **list)
{
	if (list == NULL)
	{
		printf("[error : deleteCircularList] CircularList is Null.\n");
		return;
	}
	while ((*list)->currentCount > 0)
		removeCLElement(*list, 0);
	free(*list);
	*list = NULL;
}
