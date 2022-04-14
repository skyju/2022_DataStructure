/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/14 15:42:11 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i) && (i < len))
		{
			i++;
			if (*(needle + i) == '\0')
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (0);
}
