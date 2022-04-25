#include "arrayStack.h"

//생성
ArrayStack *createArrayStack(int size)
{
	ArrayStack *result;
	result = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (!result)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	result->max_size = size;
	result->count = 0;
	result->arr = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * size);
	if (!result->arr)
	{
		printf("[error] Memory allocate failed.\n");
		free(result);
		return (NULL);
	}
	memset(result->arr, 0, sizeof(ArrayStackNode) * size);
	return (result);
}

int isArrayStackFull(ArrayStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (stack->max_size == stack->count)
		return (TRUE);
	return (FALSE);
}

//푸시
int push(ArrayStack *stack, char data)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (isArrayStackFull(stack))
	{
		printf("[error] Stack is already full.\n");
		return (FALSE);
	}
	stack->arr[stack->count].data = data;
	stack->count++;
	return (TRUE);
}

int isArrayStackEmpty(ArrayStack *stack)
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
char pop(ArrayStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (isArrayStackEmpty(stack))
	{
		printf("[error] Stack is empty.\n");
		return (FALSE);
	}
	char data = stack->arr[stack->count - 1].data;
	stack->arr[stack->count - 1].data = FALSE;
	stack->count--;
	return (data);
}

//피크
char peek(ArrayStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	if (isArrayStackEmpty(stack))
	{
		printf("[error] Stack is empty.\n");
		return (FALSE);
	}
	return (stack->arr[stack->count - 1].data);
}

// display
void displayArrayStack(ArrayStack *stack)
{
	if (stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return;
	}
	if (isArrayStackEmpty(stack))
	{
		printf("[display] Stack is empty.\n");
		return;
	}
	printf("[display]\nStack size : %d\n", stack->max_size);
	printf("Now element number : %d\n", stack->count);
	printf("---------------------\n");
	for (int i = stack->max_size - 1; i >= stack->count; i--)
		printf("[%d] : Empty\n", i);
	for (int i = stack->count - 1; i >= 0; i--)
		printf("[%d] : %c\n", i, stack->arr[i].data);
}

//삭제
int deleteArrayStack(ArrayStack **stack)
{
	if (*stack == NULL)
	{
		printf("[error] Stack is NULL.\n");
		return (FALSE);
	}
	free((*stack)->arr);
	free(*stack);
	*stack = NULL;
	return (TRUE);
}