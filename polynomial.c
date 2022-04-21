#include "polynomial.h"

PolyList *createPolyList()
{
	PolyList *result = NULL;

	result = malloc(sizeof(PolyList));
	if (!result)
	{
		printf("[error : createPolyList] Memory allocation failed.\n");
		return (NULL);
	}

	//초기화 진행
	result->currentElementCount = 0;
	return (result);
}

// 바뀜
int addPolyListData(PolyList *list, int index, Term data)
{
	PolyListNode *prev_Node;
	PolyListNode *new_Node;

	if (list == NULL)
	{
		printf("[error : addPolyListData] PolyList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentElementCount)
	{
		printf("[error : addPolyListData] Invalid index.\n");
		return (FALSE);
	}
	new_Node = (PolyListNode *)malloc(sizeof(PolyListNode *));
	if (!new_Node)
	{
		printf("[error : addPolyListData] Memory allocation failed.\n");
		return (FALSE);
	}

	prev_Node = &(list->head);
	for (int i = 0; i < index; i++)
	{
		prev_Node = prev_Node->next;
	}

	new_Node->data = data;
	new_Node->next = prev_Node->next;
	prev_Node->next = new_Node;
	list->currentElementCount += 1;

	return (TRUE);
}

int addPolyListNodeLast(PolyList *list, double coef, int degree)
{
	int index;
	Term term = {
		0,
	};

	if (list == NULL)
	{
		printf("[error : addPolyListNodeLast] PolyList is Null.\n");
		return (FALSE);
	}

	term.coef = coef;
	term.degree = degree;
	index = list->currentElementCount;
	return (addPolyListData(list, index, term));
}

PolyList *polyAddCal(PolyList *a, PolyList *b)
{
	PolyList *result;
	PolyListNode *a_node, *b_node;
	int coef_sum;

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

	a_node = a->head.next;
	b_node = b->head.next;
	while (a_node != NULL && b_node != NULL)
	{
		int a_degree = a_node->data.degree;
		int b_degree = b_node->data.degree;
		if (a_degree > b_degree)
		{
			coef_sum = a_node->data.coef;
			addPolyListNodeLast(result, coef_sum, a_degree);
			a_node = a_node->next;
		}
		else if (a_degree == b_degree)
		{
			coef_sum = a_node->data.coef + b_node->data.coef;
			addPolyListNodeLast(result, coef_sum, a_degree);
			a_node = a_node->next;
			b_node = b_node->next;
		}
		else // A의 차수 < B의 차수
		{
			coef_sum = b_node->data.coef;
			addPolyListNodeLast(result, coef_sum, b_degree);
			b_node = b_node->next;
		}
	}

	// 잔존처리
	while (a_node != NULL)
	{
		coef_sum = a_node->data.coef;
		addPolyListNodeLast(result, coef_sum, a_node->data.degree);
		a_node = a_node->next;
	}
	
	while (b_node != NULL)
	{
		coef_sum = b_node->data.coef;
		addPolyListNodeLast(result, coef_sum, b_node->data.degree);
		b_node = b_node->next;
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
	PolyListNode *tmp = NULL;

	if (list == NULL)
	{
		printf("[error : displayPolyList] PolyList is Null.\n");
		return;
	}

	printf("Current Element Count : %d\n", list->currentElementCount);
	printf("----[element display]----\n");
	tmp = &(list->head);
	for (int i = 0; i < list->currentElementCount; i++)
	{
		tmp = tmp->next;
		printf("%.1fx^%d\n", tmp->data.coef, tmp->data.degree);
	}
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

int main(void)
{
	PolyList *a = NULL;
	PolyList *b = NULL;
	PolyList *c = NULL;

	a = createPolyList();
	b = createPolyList();

	if (!a && !b)
	{
		addPolyListNodeLast(a, 7, 6);
		addPolyListNodeLast(a, 3, 5);
		addPolyListNodeLast(a, 5, 2);
		displayPolyList(a);
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

		addPolyListNodeLast(b, 1, 5);
		addPolyListNodeLast(b, 2, 4);
		addPolyListNodeLast(b, 3, 2);
		addPolyListNodeLast(b, 4, 0);
		displayPolyList(b);

		c = polyAddCal(a, b);
		displayPolyList(c);
	}
}