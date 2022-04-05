/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:53:50 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/05 16:15:36 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	s_len;
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		f(i, &s[i]);
		++i;
	}
}
