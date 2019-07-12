/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_rshift.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 21:24:54 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 10:18:00 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>
#include <ft_string.h>

void	ft_bigint_rshift(t_bigint *bi, size_t n)
{
	size_t	i;
	size_t	shift;

	shift = n >> 5;
	if (shift >= bi->size)
	{
		*bi = ft_bigint_new(0);
		return ;
	}
	ft_memmove(bi->arr, bi->arr + shift, (bi->size - shift) << 2);
	bi->size -= shift;
	ft_bzero(bi->arr + bi->size, shift << 2);
	n &= 0x1F;
	i = 0;
	while (i < bi->size - 1 && n)
	{
		bi->arr[i] = bi->arr[i] >> n | bi->arr[i + 1] << (32 - n);
		++i;
	}
	bi->arr[i] >>= (i < BI_MAX_SIZE) ? n : 0;
	if (bi->size && !bi->arr[bi->size - 1] && n)
		bi->size--;
}
