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

	result->currentElementCount = 0;
	result->head.next = &(result->head);
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
	CircularListNode* prev_Node;
	CircularListNode* new_Node;

	if (list == NULL) {
		printf("[error : addCLElement] CirculrList is NULL.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentElementCount) {
		printf("[error : addCLElement] Invalid index\n");
		return (FALSE);
	}
	new_Node = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (!new_Node) {
		printf("[error : addCLElement] Memory allocation failed\n");
		return (FALSE);
	}

	*new_Node = element;
	prev_Node = &(list->head);
	for (int i = 0; i < index ; i++)
		prev_Node = prev_Node->next;
	new_Node->next = prev_Node->next;
	prev_Node->next = new_Node;
	list->currentElementCount++;
	if (new_Node->next == NULL) {
		new_Node->next = new_Node;
	}
	return (TRUE);
}

// 원소 삭제
int removeCLElement(CircularList *list, int index)
{
	CircularListNode* prev_Node;
	CircularListNode* del_Node;

	if (list == NULL) {
		printf("[error : removeCLElement] CircularList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount) {
		printf("[error : removeCLElement] Invalid index\n");
		return (FALSE);
	}

	prev_Node = &(list->head);

	for (int i = 0; i < index; i++)
		prev_Node = prev_Node->next;

	del_Node = prev_Node->next;
	prev_Node->next = del_Node->next;
	list->currentElementCount--;

	if (list->currentElementCount == 0)
		list->head.next = NULL;
	free(del_Node);

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
	if (index < 0 || index >= list->currentElementCount)
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
	printf("Current Element Count : %d\n", list->currentElementCount);
	printf("----[element display]----\n");
	tmp = &(list->head);
	for (int i = 0; i < list->currentElementCount; i++)
	{
		tmp = tmp->next;
		printf("[%d]'s element : %d\n", i, tmp->data);
	}
}

// 초기화
void clearCircularList(CircularList *list)
{
	if (list == NULL) {
		printf("[error : clearCircularList] CircularList is Null.\n");
		return;
	}
	int cnt = list->currentElementCount;
	for (int i = 0; i < cnt; i++) {
		removeCLElement(list, 0);
	}
}

// 길이
int getCircularListLength(CircularList *list)
{
	if (list == NULL)
	{
		printf("[error : getCircularListLength] CircularList is Null.\n");
		return (FALSE);
	}
	return (list->currentElementCount);
}

// 삭제
void deleteCircularList(CircularList **list)
{
	if (list == NULL)
	{
		printf("[error : deleteCircularList] CircularList is Null.\n");
		return;
	}
	while ((*list)->currentElementCount > 0)
		removeCLElement(*list, 0);
	free(*list);
	*list = NULL;
}
