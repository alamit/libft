/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:28:26 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:06:46 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*res;

	res = dst;
	while (n)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		src++;
		dst++;
		n--;
	}
	return (res);
}
