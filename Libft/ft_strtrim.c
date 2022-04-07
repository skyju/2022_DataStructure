/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:53:50 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/07 16:19:00 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cal_start(char const *s, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s[i]) == 0)
			break ;
		++i;
	}
	return (i);
}

int	ft_cal_end(char const *s, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s[len - i - 1]) == 0)
			break ;
		++i;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	s1_len = (size_t)ft_strlen((char *)s1);
	start = ft_cal_start(s1, set, s1_len);
	end = ft_cal_end(s1, set, s1_len);
	if (start >= end)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, ((char *)s1 + start), end - start + 1);
	return (res);
}
