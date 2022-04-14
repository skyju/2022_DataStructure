/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/14 16:12:25 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = ft_strlen(src);
	while (*(src + i) && i + 1 < size)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	if (size > 0)
		*(dest + i) = '\0';
	return (src_length);
}
