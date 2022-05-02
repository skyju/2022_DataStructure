#include "polynomial.h"

PolyList* createPolyList()
{
	PolyList *result = NULL;

	result = (PolyList *)malloc(sizeof(PolyList));
	if (!result) {
		printf("[error : createPolyList] Memory allocation failed.\n");
		return (NULL);
	}

	result->currentElementCount = 0;
	result->head.next = NULL;
	return (result);
}

// 추가
int addPLElement(PolyList *list, int index, PolyListNode element)
{
	PolyListNode* prev_Node;
	PolyListNode* new_Node;

	if (list == NULL) {
		printf("[error : addPolyListData] PolyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentElementCount) {
		printf("[error : addPolyListData] Invalid index.\n");
		return (FALSE);
	}
	new_Node = (PolyListNode *)malloc(sizeof(PolyListNode *));
	if (!new_Node) {
		printf("[error : addPolyListData] Memory allocation failed.\n");
		return (FALSE);
	}

	// 이전 노드 setting
	// index이 0인 경우 때문에 우선 헤더 노드 주소값을 넣어놓음
	prev_Node = &(list->head);
	for (int i = 0; i < index; i++) {
		prev_Node = prev_Node->next;
	}
	
	// 생성 노드 할당 및 새로운 연결해주기
	*new_Node = element;
	if (index == list->currentElementCount) { // 마지막 노드 추가인 경우
		new_Node->next = NULL;
		prev_Node->next = new_Node;
	} else {
		new_Node->next = prev_Node->next;
		prev_Node->next = new_Node;
	}
	list->currentElementCount += 1;

	return (TRUE);
}

int addPolyNodeLast(PolyList *list, double coef, int degree)
{
	int index;
	PolyListNode* new_Node;

	if (list == NULL) {
		printf("[error : addPolyNodeLast] PolyList is Null.\n");
		return (FALSE);
	}
	new_Node = (PolyListNode *)malloc(sizeof(PolyListNode *));
	if (!new_Node) {
		printf("[error : addPolyNodeLast] Memory allocation failed.\n");
		return (FALSE);
	}
	
	(*new_Node).coef = coef;
	(*new_Node).degree = degree;
	index = getPolyListLength(list);
	return (addPLElement(list, index, *new_Node));
}

PolyList *PolyListSort(PolyList *list)
{
    for (int i = 0; i < list->currentElementCount; i++) {
    	PolyListNode *prev = list->head.next;
    	PolyListNode *curr = list->head.next->next;
    	if (curr) {
    	do {
        	if (curr->degree > prev->degree){
           		int temp2 = curr->degree;
           		curr->degree = prev->degree;
           		prev->degree = temp2;
	            int temp3 = curr->coef;
    	        curr->coef = prev->coef;
        	    prev->coef = temp3;

     	    	prev = &(list->head);
        	    curr = list->head.next;
        	}
            prev = prev->next;
            curr = curr->next;
        } while(curr);
    	}
    }
    return (list);
}

PolyList *polyAddCal(PolyList *a, PolyList *b)
{
	PolyList *result;
	PolyListNode *a_node;
	PolyListNode *b_node;
	int b_node_cnt = b->currentElementCount;
	int	a_node_cnt = a->currentElementCount;

	if (a == NULL && b == NULL)
	{
		printf("[error : polyAddCal] PolyList is All Null.\n");
		return (NULL);
	}
	result = createPolyList();
	if (!result)
	{
		printf("[error : polyAddCal] Memory allocation failed.\n");
		return (NULL);
	}

	a_node = PolyListSort(a)->head.next;
	b_node = PolyListSort(b)->head.next;
	while (a_node_cnt > 0 && b_node_cnt > 0) {
		int a_degree = a_node->degree;
		int b_degree = b_node->degree;
		if (a_degree > b_degree) {
			addPolyNodeLast(result, a_node->coef, a_degree);
			a_node = a_node->next;
		} else if (a_degree == b_degree) {
			addPolyNodeLast(result, a_node->coef + b_node->coef, a_degree);
			a_node = a_node->next;
			b_node = b_node->next;
		} else {
			addPolyNodeLast(result, b_node->coef, b_degree);
			b_node = b_node->next;
		}
		a_node_cnt -= 1;
		b_node_cnt -= 1;
	}
	
	// 잔존처리
	while (a_node_cnt > 0) {
		addPolyNodeLast(result, a_node->coef, a_node->degree);
		a_node = a_node->next;
		a_node_cnt -= 1;
	}
	
	while (b_node_cnt > 0) {
		addPolyNodeLast(result, b_node->coef, b_node->degree);
		b_node = b_node->next;
		b_node_cnt -= 1;
	}
	return (result);
}

int removePLElement(PolyList *list, int index)
{
	PolyListNode *prev_Node;
	PolyListNode *del_Node;

	if (list == NULL)
	{
		printf("[error : removePLElement] PolyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount)
	{
		printf("[error : removePLElement] Invalid index.\n");
		return (FALSE);
	}

	prev_Node = &(list->head);
	if (index == 0)
	{
		list->head = *(prev_Node->next);
		free(prev_Node->next);
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			prev_Node = prev_Node->next;
		}
		del_Node = prev_Node->next;
		prev_Node->next = del_Node->next;
		free(del_Node);
	}
	list->currentElementCount -= 1;

	return (TRUE);
}

PolyListNode *getPLElement(PolyList *list, int index)
{
	PolyListNode *result = NULL;

	if (list == NULL)
	{
		printf("[error : getPLElement] PolyList is Null.\n");
		return (NULL);
	}
	if (index < 0 || index >= list->currentElementCount)
	{
		printf("[error : getPLElement] Invalid index.\n");
		return (NULL);
	}

	result = &(list->head);
	for (int i = 0; i <= index; i++)
		result = result->next;

	return (result);
}
void displayPolyList(PolyList *list)
{
	PolyListNode* tmp = NULL;

	if (list == NULL) {
		printf("[error : displayPolyList] PolyList is Null.\n");
		return;
	}
	printf("COUNT: %d\n", list->currentElementCount);
	printf("----[display]----\n");
	tmp = &(list->head);
	for (int i = 0; i < list->currentElementCount; i++)
	{
		tmp = tmp->next;
		if (tmp != NULL) {
			if (i > 0) {
				printf(" + ");
			}
			printf("%.1fx^%d", tmp->coef, tmp->degree);
		}
	}
	printf("\n");
}

void clearPolyList(PolyList *list)
{
	PolyListNode *tmp = NULL;
	PolyListNode *tmp2 = NULL;

	if (list == NULL)
	{
		printf("[error : clearPolyList] PolyList is Null.\n");
		return;
	}
	tmp = &(list->head);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp;
		free(tmp2->next);
	}
	list->currentElementCount = 0;
}

int getPolyListLength(PolyList *list)
{
	if (list == NULL)
	{
		printf("[error : getPolyListLength] PolyList is Null.\n");
		return (FALSE);
	}
	return (list->currentElementCount);
}
void deletePolyList(PolyList **list)
{
	if (list == NULL)
	{
		printf("[error : deletePolyList] PolyList is Null.\n");
		return;
	}
	while ((*list)->currentElementCount > 0)
		removePLElement(*list, 0);
	free(*list);
	*list = NULL;
}
