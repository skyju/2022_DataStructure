/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/14 18:17:09 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		pos;
	int		flag;
	size_t	res;

	pos = 0;
	while (str[pos] != '\0' && ft_isspace(str[pos]))
		++pos;
	flag = 1;
	if (str[pos] == '-')
		flag = -1;
	if (str[pos] == '-' || str[pos] == '+')
		++pos;
	res = 0;
	while (str[pos] != '\0' && str[pos] >= '0' && str[pos] <= '9')
	{
		res *= 10;
		res += (str[pos] - '0');
		++pos;
	}
	if (res > 2147483647 && flag == 1)
		return (-1);
	if (res > 2147483648 && flag == -1)
		return (0);
	return (res * flag);
}
