/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_div.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:04:56 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 14:07:33 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>

uint32_t	ft_bigint_div(t_bigint *mod, const t_bigint *div, uint32_t q_max)
{
	t_bigint	tmp;
	uint32_t	q;

	q = 0;
	tmp = *div;
	while (ft_bigint_cmp(mod, &tmp) <= 0 && q < q_max)
	{
		ft_bigint_add(&tmp, div);
		++q;
	}
	if (q > 0)
	{
		ft_bigint_sub(&tmp, div);
		ft_bigint_sub(mod, &tmp);
	}
	return (q);
}
