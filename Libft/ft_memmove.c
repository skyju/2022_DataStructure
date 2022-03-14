/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/03/14 15:09:30 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_tmp;
	unsigned char	*s_tmp;

	if (dst == src || len == 0)
		return (dst);
	if (dst <= src)
	{
		d_tmp = dst;
		s_tmp = src;
		while (len--)
			*d_tmp++ = *s_tmp++;
	}
	else
	{
		d_tmp = dst;
		d_tmp += len;
		s_tmp = src;
		while (len--)
			*--d_tmp = *--s_tmp;
	}
	return (dst);
}
