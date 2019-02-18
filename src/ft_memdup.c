/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:02:49 by alamit            #+#    #+#             */
/*   Updated: 2019/02/18 19:39:44 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memdup(const void *src, size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	return (ft_memcpy(res, src, size));
}
