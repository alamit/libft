/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_mulpow10.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:14 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 10:03:12 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>

static void	mul5p6(t_bigint *bi)
{
	t_bigint	tmp;

	tmp = *bi;
	ft_bigint_lshift(bi, 14);
	ft_bigint_add(bi, &tmp);
	ft_bigint_lshift(&tmp, 3);
	ft_bigint_add(bi, &tmp);
	ft_bigint_lshift(&tmp, 5);
	ft_bigint_add(bi, &tmp);
	ft_bigint_lshift(&tmp, 2);
	ft_bigint_sub(bi, &tmp);
}

static void	mul5(t_bigint *bi)
{
	t_bigint tmp;

	tmp = *bi;
	ft_bigint_lshift(&tmp, 2);
	ft_bigint_add(bi, &tmp);
}

void		ft_bigint_mulpow10(t_bigint *bi, size_t n)
{
	size_t		i;

	i = n;
	while (i > 6)
	{
		mul5p6(bi);
		i -= 6;
	}
	while (i && i--)
		mul5(bi);

	ft_bigint_lshift(bi, n);
}
