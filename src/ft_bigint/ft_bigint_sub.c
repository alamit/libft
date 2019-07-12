/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 21:17:09 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 07:18:12 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>

/*
** NOTE: ONLY IF SRC < DST
*/

void	ft_bigint_sub(t_bigint *dst, const t_bigint *src)
{
	size_t		i;
	char		carry;
	uint32_t	tmp;

	i = 0;
	carry = 0;
	while (i < BI_MAX_SIZE && (i <= src->size || carry))
	{
		tmp = dst->arr[i];
		dst->arr[i] -= carry;
		carry = dst->arr[i] > tmp;
		tmp = dst->arr[i];
		dst->arr[i] -= src->arr[i];
		carry += dst->arr[i] > tmp;
		++i;
	}
	while (!dst->arr[dst->size - 1] && dst->size)
		--dst->size;
}
