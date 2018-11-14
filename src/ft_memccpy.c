/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:04:43 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 12:18:50 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		if (*(unsigned char *)dst == (unsigned char)c)
			return (dst + 1);
		++src;
		++dst;
		--n;
	}
	return (NULL);
}
