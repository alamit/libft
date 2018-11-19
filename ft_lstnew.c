/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:56:05 by alamit            #+#    #+#             */
/*   Updated: 2018/11/19 15:01:43 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list	*res;

	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		res->content = ft_memalloc(content_size);
		ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next =

}
