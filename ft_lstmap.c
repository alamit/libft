/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:49:13 by alamit            #+#    #+#             */
/*   Updated: 2018/11/23 11:09:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*res;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL || (new = f(new)) == NULL)
		return (NULL);
	res = new;
	while ((lst = lst->next))
	{
		new->next = ft_lstnew(lst->content, lst->content_size);
		if (new->next == NULL || (new->next = f(new->next)) == NULL)
		{
			ft_lstdel(&res, NULL);
			return (NULL);
		}
		new = new->next;
	}
	return (res);
}
