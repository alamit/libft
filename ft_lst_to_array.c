/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 05:03:37 by alamit            #+#    #+#             */
/*   Updated: 2019/01/28 05:10:11 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	**ft_lst_to_array(t_list *lst)
{
	size_t	i;
	size_t	len;
	void	**res;

	i = 0;
	len = ft_lstlen(lst);
	if (!(res = malloc(len * sizeof(void *) + 1)))
		return (NULL);
	while (i < len)
	{
		res[i] = lst->content;
		++i;
	}
	res[i] = NULL;
	return (res);
}
