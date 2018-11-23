/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:48:08 by alamit            #+#    #+#             */
/*   Updated: 2018/11/23 09:40:24 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

void	f(t_list *lst)
{
	ft_putendl((const char *)lst->content);
}

t_list *f2(t_list *lst)
{
	lst->content = "a";
	return (lst);
}

int		main(void)
{
	t_list *lst = ft_lstnew(0, 0);
	t_list *lst2;

	for (int i = 0; i < 10; i++)
	{
		ft_lstadd(&lst, ft_lstnew(ft_itoa(i), 1));
	}
	ft_lstiter(lst, f);
	lst2 = ft_lstmap(lst, f2);
	ft_lstiter(lst2, f);
}
