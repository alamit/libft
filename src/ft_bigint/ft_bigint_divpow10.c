/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_divpow10.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:14:17 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 09:16:37 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>

uint32_t	ft_bigint_divpow10(t_bigint *mod, size_t pow, uint32_t q_max)
{
	t_bigint	div;

	div = ft_bigint_new(1);
	ft_bigint_mulpow10(&div, pow);
	return (ft_bigint_div(mod, &div, q_max));
}
