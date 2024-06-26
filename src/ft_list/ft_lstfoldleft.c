/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfoldleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:10:29 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:28:57 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <stddef.h>

t_list	*ft_lstfoldleft(t_list *lst,
						t_list *zero,
						t_list *(*op)(t_list *, t_list *))
{
	if (op == NULL || zero == NULL)
		return (zero);
	while (lst)
	{
		zero = op(zero, lst);
		lst = lst->next;
	}
	return (zero);
}
