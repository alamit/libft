/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 05:03:37 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 21:54:35 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <stdlib.h>

void	**ft_lst_to_array(t_list *lst)
{
	size_t	i;
	size_t	len;
	void	**res;

	i = 0;
	len = ft_lstlen(lst);
	if (lst == NULL || !(res = malloc(len * sizeof(void *) + 1)))
		return (NULL);
	while (i < len)
	{
		res[i] = lst->content;
		++i;
	}
	res[i] = NULL;
	return (res);
}
