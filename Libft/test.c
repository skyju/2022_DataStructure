#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{	
	printf("1. ft_atoi test\n");
	char *str = " -1234212";
	int	n = ft_atoi(str);
	printf("expected: -1234212\n");
	printf("reply: %d\n", n);

	printf("2. ft_bzero test\n");
	
	printf("3. ft_calloc test\n");

	printf("4. ft_isalnum test\n");
	printf("5. ft_isalpha test\n");
	printf("6. ft_isascii test\n");
	printf("7. ft_isdigit test\n");
	printf("8. ft_isprint test\n");

	printf("9. ft_itoa test\n");
	n = -2147483648;
	int n2 = -2147483647;
	int n3 = 2147483647;
	int n4 = 12352315;
	printf("expected: -2147483648\n");
	printf("reply: %s\n", ft_itoa(n));
	printf("test2 : %s\n", ft_itoa(n2));
	printf("test2 : %s\n", ft_itoa(n3));
	printf("test2 : %s\n", ft_itoa(n4));

	ft_putstr_fd(argv[0], 1);
	if (argc != 1)
	{
		ft_putstr_fd(argv[1], 1);
	}
	ft_putnbr_fd(argc, 1);
}