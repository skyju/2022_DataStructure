/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/14 16:14:05 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	index;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	index = 0;
	while (*(src + index) && dest_length + index + 1 < size)
	{
		*(dest + dest_length + index) = *(src + index);
		++index;
	}
	*(dest + dest_length + index) = '\0';
	if (size < dest_length)
		return (src_length + size);
	return (src_length + dest_length);
}
