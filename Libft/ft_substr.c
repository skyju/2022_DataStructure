/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:45:51 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/05 16:19:12 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	res_i;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	res_i = 0;
	while (s[i])
	{
		if (i >= start && res_i < len)
			res[res_i++] = s[i];
		++i;
	}
	res[res_i] = '\0';
	return (res);
}
