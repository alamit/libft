/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_lshift.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 21:24:54 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 10:17:46 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>
#include <ft_string.h>

void	ft_bigint_lshift(t_bigint *bi, size_t n)
{
	size_t			i;
	size_t			shift;
	size_t			tmp;

	shift = n >> 5;
	if (shift >= BI_MAX_SIZE)
	{
		*bi = ft_bigint_new(0);
		return ;
	}
	tmp = bi->size < BI_MAX_SIZE - shift ? bi->size : BI_MAX_SIZE - shift;
	ft_memmove(bi->arr + shift, bi->arr, tmp << 2);
	ft_bzero(bi->arr, shift << 2);
	bi->size += shift;
	n &= 0x1F;
	i = bi->size < BI_MAX_SIZE ? bi->size : BI_MAX_SIZE - 1;
	while (i && n)
	{
		bi->arr[i] = bi->arr[i] << n | bi->arr[i - 1] >> (32 - n);
		--i;
	}
	bi->arr[0] <<= n;
	if (bi->size + 1 < BI_MAX_SIZE && bi->arr[bi->size])
		bi->size++;
}
