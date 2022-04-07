/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:53:50 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/07 16:43:03 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	malloc_size_cal(long int nbr)
{
	int	cnt;

	cnt = 1;
	if (nbr < 0)
	{
		++cnt;
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		++cnt;
	}
	return (cnt);
}

void	make_str(char *res, long int nbr, int i)
{
	if (nbr < 0)
	{
		*res = '-';
		nbr *= -1;
	}
	if (nbr / 10 != 0)
		make_str(res, nbr / 10, i - 1);
	else
	{
		*(res + i) = nbr + '0';
		return ;
	}
	make_str(res, nbr % 10, i);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		malloc_size;

	malloc_size = malloc_size_cal(nbr);
	res = (char *)malloc(sizeof(char) * (malloc_size + 1));
	if (!res)
		return (NULL);
	make_str(res, nbr, malloc_size - 1);
	res[malloc_size] = '\0';
	return (res);
}
