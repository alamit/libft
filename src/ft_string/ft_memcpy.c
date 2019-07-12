/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:28:26 by alamit            #+#    #+#             */
/*   Updated: 2019/04/04 05:06:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <inttypes.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*res;

	res = dst;
	while (n / sizeof(uint64_t))
	{
		*(uint64_t *)dst = *(uint64_t *)src;
		src += sizeof(uint64_t);
		dst += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (n)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		src++;
		dst++;
		n--;
	}
	return (res);
}
