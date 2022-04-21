#include "doublyList.h"

// 생성
DoublyList *createDoublyList()
{
	DoublyList *result = NULL;

	result = malloc(sizeof(DoublyList));
	if (!result)
	{
		printf("[error : createDoublyList] Memory allocation failed.\n");
		return (NULL);
	}

	//초기화 진행
	result->currentElementCount = 0;
	result->head.left = &(result->head);
	result->head.right = &(result->head);

	return (result);
}

// 원소 대체
int replaceDLElement(DoublyList *list, int index, DoublyListNode element)
{
	DoublyListNode *tmp;

	if (list == NULL)
	{
		printf("[error : replaceDLElement] DoublyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount)
	{
		printf("[error : replaceDLElement] Invalid index.\n");
		return (FALSE);
	}

	tmp = &(list->head);
	for (int i = 0; i <= index; i++)
	{
		tmp = tmp->right;
	}
	tmp->data = element.data;

	return (TRUE);
}

// 원소 추가
int addDLElement(DoublyList *list, int index, DoublyListNode element)
{
	DoublyListNode *prev_Node;
	DoublyListNode *new_Node;

	if (list == NULL)
	{
		printf("[error : addDLElement] DoublyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentElementCount)
	{
		printf("[error : addDLElement] Invalid index.\n");
		return (FALSE);
	}
	new_Node = (DoublyListNode *)malloc(sizeof(DoublyListNode *));
	if (!new_Node)
	{
		printf("[error : addDLElement] Memory allocation failed.\n");
		return (FALSE);
	}

	prev_Node = &(list->head);
	for (int i = 0; i < index; i++)
		prev_Node = prev_Node->right;

	// 생성 노드 할당 및 새로운 연결해주기
	*new_Node = element;
	new_Node->right = prev_Node->right;
	new_Node->left = prev_Node;
	prev_Node->right = new_Node;
	// 헷갈릴 수 있는 부분
	new_Node->right->left = newNode;
	//
	list->currentElementCount += 1;

	return (TRUE);
}

// 원소 삭제
int removeDLElement(DoublyList *list, int index)
{
	DoublyListNode *prev_Node;
	DoublyListNode *del_Node;

	if (list == NULL)
	{
		printf("[error : removeDLElement] DoublyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount)
	{
		printf("[error : removeDLElement] Invalid index.\n");
		return (FALSE);
	}

	// 노드 삭제 및 새로운 연결해주기
	prev_Node = &(list->head);
	if (index == 0)
	{
		list->head = *(prev_Node->right);
		prev_Node->right->left = list->head;
		free(prev_Node->right);
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			prev_Node = prev_Node->right;
		}
		del_Node = prev_Node->right;
		prev_Node->right = del_Node->right;
		del_Node->right->left = prev_Node;
		free(del_Node);
	}
	list->currentElementCount -= 1;

	return (TRUE);
}

// 원소 가져오기
DoublyList *getDLElement(DoublyList *list, int index)
{
	DoublyListNode *result;

	if (list == NULL)
	{
		printf("[error : getDLElement] DoublyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount)
	{
		printf("[error : getDLElement] Invalid index.\n");
		return (NULL);
	}

	result = &(list->head);
	for (int i = 0; i <= index; i++)
	{
		result = result->right;
	}

	return (result);
}

// 정보 출력
void displayDoublyList(DoublyList *list)
{
	DoublyListNode *tmp = NULL;

	if (list == NULL)
	{
		printf("[error : displayDoublyList] DoublyList is Null.\n");
		return;
	}

	printf("Current Element Count : %d\n", list->currentElementCount);
	printf("----[element display]----\n");
	tmp = &(list->head);
	for (int i = 0; i < list->currentElementCount; i++)
	{
		printf("[%d]'s element : %d\n", i, tmp->data);
		tmp = tmp->right;
	}
}

// 초기화
void clearDoublyList(DoublyList *list)
{
	DoublyListNode *tmp = NULL;
	DoublyListNode *tmp2 = NULL;

	if (list == NULL)
	{
		printf("[error : clearDoublyList] DoublyList is Null.\n");
		return;
	}
	tmp = &(list->head);
	while (tmp->right != NULL)
	{
		tmp = tmp->right;
		tmp2 = tmp;
		free(tmp2->right);
	}
	list->currentElementCount = 0;
}

// 길이
int getDoublyListLength(DoublyList *list)
{
	if (list == NULL)
	{
		printf("[error : getDoublyListLength] DoublyList is Null.\n");
		return (FALSE);
	}
	return (list->currentElementCount)
}

// 삭제
void deleteDoublyList(DoublyList **list)
{
	if (list == NULL)
	{
		printf("[error : deleteDoublyList] DoublyList is Null.\n");
		return;
	}
	while ((*list)->currentElementCount > 0)
		removeDLElement(*list, 0);
	free(*list);
	*list = NULL;
}