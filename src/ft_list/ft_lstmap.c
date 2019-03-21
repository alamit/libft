/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:49:13 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 21:56:10 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <stdlib.h>

static void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*res;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL || (new = (f) ? f(new) : new) == NULL)
		return (NULL);
	res = new;
	while ((lst = lst->next))
	{
		new->next = ft_lstnew(lst->content, lst->content_size);
		if (new->next == NULL
			|| (new->next = (f) ? f(new->next) : new->next) == NULL)
		{
			ft_lstdel(&res, del);
			return (NULL);
		}
		new = new->next;
	}
	return (res);
}
