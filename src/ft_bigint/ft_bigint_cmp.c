/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:10:00 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 14:19:41 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>

int		ft_bigint_cmp(const t_bigint *a, const t_bigint *b)
{
	size_t	i;

	if (a->size != b->size)
		return (b->size > a->size ? 1 : -1);
	i = a->size;
	while (--i)
	{
		if (a->arr[i] != b->arr[i])
			return (b->arr[i] > a->arr[i] ? 1 : -1);
	}
	return (0);
}
