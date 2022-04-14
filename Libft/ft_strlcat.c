/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/14 18:22:42 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	i = 0;
	if (size < dest_length + 1)
		return (src_length + size);
	while (*(src + i) && dest_length + i + 1 < size)
	{
		*(dest + dest_length + i) = *(src + i);
		++i;
	}
	*(dest + dest_length + i) = '\0';
	return (src_length + dest_length);
}
