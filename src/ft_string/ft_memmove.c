/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:24:15 by alamit            #+#    #+#             */
/*   Updated: 2019/04/04 05:06:30 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <inttypes.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	dst += n;
	src += n;
	while (n / sizeof(uint64_t))
	{
		dst -= sizeof(uint64_t);
		src -= sizeof(uint64_t);
		*(uint64_t *)dst = *(uint64_t *)src;
		n -= sizeof(uint64_t);
	}
	while (n)
	{
		dst--;
		src--;
		*(unsigned char *)dst = *(unsigned char *)src;
		n--;
	}
	return (dst);
}
