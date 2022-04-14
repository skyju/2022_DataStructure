/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:06:03 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/14 18:16:27 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char s, char c)
{
	return (s == c);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	words_num;

	i = 0;
	words_num = 0;
	if (!s[0])
		return (0);
	while (s[i] && is_sep(s[i], c))
		++i;
	while (s[i])
	{
		if (is_sep(s[i], c))
		{
			words_num++;
			while (s[i] && is_sep(s[i], c))
				++i;
			continue ;
		}
		++i;
	}
	if (s[i - 1] != c)
		words_num++;
	return (words_num);
}

char	*ft_make_str(char *str, char c)
{
	char	*res;
	int		res_len;
	int		i;

	res_len = 0;
	while (*(str + res_len) && !is_sep(str[res_len], c))
		++res_len;
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_len)
	{
		res[i] = str[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		res_i;

	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	res_i = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			++i;
		if (s[i] && !is_sep(s[i], c))
			res[res_i++] = ft_make_str((char *)(s + i), c);
		while (s[i] && !is_sep(s[i], c))
			++i;
	}
	res[res_i] = 0;
	return (res);
}
