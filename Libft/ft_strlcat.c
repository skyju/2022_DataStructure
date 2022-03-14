/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/03/14 14:27:56 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	index;

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
