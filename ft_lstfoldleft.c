/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfoldleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:10:29 by alamit            #+#    #+#             */
/*   Updated: 2018/11/23 14:48:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfoldleft(t_list *lst,
						t_list *zero,
						t_list *(*op)(t_list *, t_list *))
{
	if (lst == NULL)
		return (zero);
	else if (zero == NULL || op == NULL)
		return (NULL);
	return (ft_lstfoldleft(lst->next, op(zero, lst), op));
}
