/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:49:13 by alamit            #+#    #+#             */
/*   Updated: 2018/11/21 14:22:56 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t size)
{
	(void)size;
	(void)content;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*res;
	t_list	*new;

	new = f(ft_lstnew(lst->content, lst->content_size));
	res = new;
	if (res == NULL)
		return (NULL);
	while ((lst = lst->next))
	{
		new->next = f(ft_lstnew(lst->content, lst->content_size));
		new = new->next;
		if (new == NULL)
		{
			ft_lstdel(&res, &del);
			return (NULL);
		}
	}
	return (res);
}
