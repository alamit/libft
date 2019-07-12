/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 05:27:14 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 10:41:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>

void	ft_bigint_add(t_bigint *dst, const t_bigint *src)
{
	size_t		i;
	uint32_t	carry;
	uint64_t	tmp;

	i = 0;
	carry = 0;
	while (i < BI_MAX_SIZE && (i < src->size || carry))
	{
		tmp = (uint64_t)dst->arr[i] + (uint64_t)src->arr[i] + carry;
		dst->arr[i] = UINT32_MAX & tmp;
		carry = tmp >> 32;
		++i;
	}
	if (dst->size + 1 < BI_MAX_SIZE && dst->arr[dst->size])
		dst->size++;
}
