/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:02:49 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:07:09 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

void	*ft_memdup(const void *src, size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	return (ft_memcpy(res, src, size));
}
