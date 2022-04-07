/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/07 16:23:15 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_tmp;
	unsigned char	*s_tmp;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		d_tmp = (unsigned char *)dst;
		s_tmp = (unsigned char *)src;
		while (len--)
			*d_tmp++ = *s_tmp++;
	}
	else
	{
		d_tmp = (unsigned char *)dst + (len - 1);
		s_tmp = (unsigned char *)src + (len - 1);
		while (len--)
			*d_tmp-- = *s_tmp--;
	}
	return (dst);
}
