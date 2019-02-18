/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:50:17 by alamit            #+#    #+#             */
/*   Updated: 2018/11/19 13:20:32 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static size_t		count_words(const char *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		if (*s != c && (!s[1] || s[1] == c))
			++res;
		++s;
	}
	return (res);
}

static size_t		wordlen(const char *s, char c)
{
	size_t res;

	res = 0;
	while (*s && *s != c)
	{
		++res;
		++s;
	}
	return (res);
}

static const char	*dup_next_word(char **dst, const char *s, char c)
{
	size_t	wlen;

	wlen = wordlen(s, c);
	*dst = (char *)malloc((wlen + 1) * sizeof(char));
	if (*dst == NULL)
		return (NULL);
	ft_strncpy(*dst, s, wlen);
	(*dst)[wlen] = '\0';
	s += wlen;
	while (*s && *s == c)
		s++;
	return (s);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (*s == c)
		++s;
	i = 0;
	while (*s)
	{
		s = dup_next_word(res + i, s, c);
		if (s == NULL)
		{
			while (i)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		++i;
	}
	res[i] = NULL;
	return (res);
}
