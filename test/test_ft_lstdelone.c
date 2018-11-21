/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:52:06 by alamit            #+#    #+#             */
/*   Updated: 2018/11/19 17:04:26 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <test42f.h>

void	del(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

void	test_ft_lstdelone(void)
{
	printf("%sTesting ft_lstdelone.%s\n", KCYN, KNRM);
	t_list	*list = NULL;
	ft_lstdelone(&list, del);
}
