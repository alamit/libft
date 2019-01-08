/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:50:17 by alamit            #+#    #+#             */
/*   Updated: 2019/01/08 17:47:30 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static void			del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
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

static const char	*dup_next_word(t_list **dst, const char *s, char c)
{
	size_t	wlen;

	wlen = wordlen(s, c);
	if (dst == NULL)
		return (NULL);
	*dst = ft_lstnew(s, wlen + 1);
	if (*dst == NULL)
		return (NULL);
	((char *)(*dst)->content)[wlen] = '\0';
	s += wlen + 1;
	return (s);
}

t_list				*ft_lststrsplit(const char *s, char c)
{
	t_list	*res;
	t_list	*current;

	if (s == NULL)
		return (NULL);
	s = dup_next_word(&res, s, c);
	current = res;
	while (*s)
	{
		s = dup_next_word(&current->next, s, c);
		current = current->next;
		if (s == NULL)
		{
			ft_lstdel(&res, del);
			return (NULL);
		}
	}
	return (res);
}
