#include "../linkedStack.c"

// 1. 여는 괄호와 닫는 괄호가 쌍을 이루어야 함
// 2. 여럿이 중첩되었을 때, 맨 안쪽 괄호부터 닫혀야 함

// 1. 여는 괄호를 만나면 -> push
// 2. 닫는 괄호를 만나면 -> pop한 후 종류를 조사

int checkBracket(char c)
{
	if (c == '(' || c == '{' || c == '[')
		return (1);
	if (c == ')' || c == '}' || c == ']')
		return (2);
	return (0);
}

int checkBracket_advanced(char open_c, char close_c)
{
	if (open_c == '(' && close_c == ')')
		return (1);
	if (open_c == '{' && close_c == '}')
		return (1);
	if (open_c == '[' && close_c == ']')
		return (1);
	return (0);
}

void math_express_test(char *src)
{
	int size;
	LinkedStack *stack;

	stack = createLinkedStack();
	if (stack == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return;
	}
	size = 0;
	while (src[size])
	{
		if (checkBracket(src[size]) == 1)
			push(stack, src[size]);
		if (checkBracket(src[size]) == 2)
		{
			if (isLinkedStackEmpty(stack))
			{
				printf("[error] Invalid math expression.\n");
				return;
			}
			if (checkBracket_advanced(pop(stack), src[size] == 0))
			{
				printf("[error] Invalid math expression.\n");
				return;
			}
		}
		++size;
	}

	// 여는 괄호가 남는 경우 check
	if (!isLinkedStackEmpty(stack))
	{
		printf("[error] Invalid math expression.\n");
		return;
	}
	deleteLinkedStack(&stack);
	printf("OK :D\n");
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("입력이 없습니다.\n");
		return (0);
	}
	else if (argc > 2)
	{
		printf("하나의 문자열만 입력해주세요.\n");
		return (0);
	}
	math_express_test(argv[1]);
}