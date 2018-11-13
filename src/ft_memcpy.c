/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:28:26 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 11:32:01 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n)
	{
		((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (dst);
}
