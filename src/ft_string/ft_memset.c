/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:10:24 by alamit            #+#    #+#             */
/*   Updated: 2019/04/04 07:38:11 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <inttypes.h>

void	*ft_memset(void *b, int c, size_t len)
{
	uint64_t	n;
	void		*res;

	res = b;
	n = (unsigned char)c;
	n = (n << 56) | (n << 48) | (n << 40) | (n << 32) | (n << 24) | (n << 16)
		| (n << 8) | n;
	while (len / sizeof(uint64_t))
	{
		*(uint64_t *)b = n;
		b += sizeof(uint64_t);
		len -= sizeof(uint64_t);
	}
	while (len)
	{
		*(unsigned char *)b = (unsigned char)c;
		len--;
		b++;
	}
	return (res);
}
