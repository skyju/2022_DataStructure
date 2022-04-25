#include "../linkedStack.c"

char *reverse_String(char *src)
{
	char *rev_str;
	int size;
	LinkedStack *stack;

	stack = createLinkedStack();
	if (stack == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	size = 0;
	while (src[size])
	{
		push(stack, src[size]);
		++size;
	}
	rev_str = (char *)calloc(sizeof(char), (size + 1));
	if (rev_str == NULL)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	for (int i = 0; i < size; i++)
		rev_str[i] = pop(stack);
	rev_str[size] = '\0';
	deleteLinkedStack(&stack);
	return (rev_str);
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		printf("입력이 없습니다.\n");
		return (0);
	} else if (argc > 2) {
		printf("하나의 문자열만 입력해주세요.\n");
		return (0);
	}
	char *src = argv[1];
	printf("역순 출력: %s\n", reverse_String(src));
}