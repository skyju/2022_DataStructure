/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:53:50 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/05 16:38:26 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		s_len;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	s_len = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!res)
		return (NULL);
	while (i < s_len)
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
