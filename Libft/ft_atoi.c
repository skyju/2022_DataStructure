/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/03/09 13:36:03 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int pos;
	int	flag;
	int	res;

	while (str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n'
		|| str[pos] == '\v' || str[pos] == '\r' || str[pos] == '\f')
	{
		++pos;
	}
	flag = 1;
	if (str[pos] == '-')
	{
		flag = -1;
		++pos;
	} else if (str[pos] == '+')
		++pos;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res *= 10;
		res += (str[pos] = '0');
		++pos;
	}
	return (res * flag);
}
