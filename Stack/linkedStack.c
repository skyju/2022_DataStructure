#include "linkedStack.h"

//생성
LinkedStack *createLinkedStack()
{
	LinkedStack *result;
	result = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (result == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	result->count = 0;
	result->head = NULL;
	return (result);
}

//푸시
int push(LinkedStack *stack, char data)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	LinkedStackNode *new_Node;
	new_Node = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
	if (new_Node == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (FALSE);
	}
	new_Node->data = data;
	// 항상 index 0에 추가된다고 생각!
	new_Node->next = stack->head; //기존에 있던 걸 뒤로 연결
	stack->head = new_Node; // 추가한걸 앞으로 연결
	stack->count++;
	return (TRUE);
}

int isLinkedStackEmpty(LinkedStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (stack->count == 0)
		return (TRUE);
	return (FALSE);
}

//팝
char pop(LinkedStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (isLinkedStackEmpty(stack))
	{
		printf("[error] Stack is empty.\n");
		return (FALSE);
	}
	LinkedStackNode *tmp = stack->head;
	char data = tmp->data;
	stack->head = stack->head->next;
	free(tmp);
	tmp->next = NULL;
	stack->count--;
	return (data);
}

//피크
char peek(LinkedStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (isLinkedStackEmpty(stack))
	{
		printf("[error] Stack is empty.\n");
		return (FALSE);
	}
	return (stack->head->data);
}

// display
void displayLinkedStack(LinkedStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return;
	}
	if (isLinkedStackEmpty(stack))
	{
		printf("[display] Stack is empty.\n");
		return;
	}
	printf("[display]\nNow element numer : %d\n", stack->count);
	printf("---------------------\n");
	LinkedStackNode *node = stack->head;
	for (int i = stack->count - 1; i >= 0; i--)
	{
		printf("[%d] : %c\n", i, node->data);
		node = node->next;
	}
}

//삭제
int deleteLinkedStack(LinkedStack **stack)
{
	if (*stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	free((*stack)->head);
	free(*stack);
	*stack = NULL;
	return (TRUE);
}