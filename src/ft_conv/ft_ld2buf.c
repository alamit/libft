/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld2buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:32:51 by alamit            #+#    #+#             */
/*   Updated: 2019/03/25 15:59:05 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>
#include <ft_conv.h>
#include <ft_string.h>

#define MIN_EXP -16445
#define MAX_EXP 16319
#define LOG10_2 0.30102999566398119521373889472449L

/*
**	Estimation of logarithm base 10 of a long double with error.
**	The error is introduced to maximize:
**	- If expb2 >=0: Overestimate the log10.
**	- If expb2 < 0: Underestimate the log10.
**	The error is always 1 or 0.
*/
static int32_t	log10_err(int32_t expb2, uint64_t mantissa)
{
	int32_t	hbit;
	int32_t	res;

	hbit = 0;
	while (!(mantissa & (1ul << 63)))
	{
		++hbit;
		mantissa <<= 1;
	}
	res = (int32_t)((long double)(hbit + expb2) * LOG10_2 - 0.69L);
	return (res >= 0 ? res + 1 : res);
}

static int		bias_pos(uint64_t mantissa)
{
	return (mantissa == (1ul << 63));
}

static int		bias_neg(uint64_t mantissa, int32_t expb2)
{
	return (bias_pos(mantissa) && expb2 > MIN_EXP);
}

static int		init(long double n, t_bigint *numerator, t_bigint *denominator,
	int32_t *expb10)
{
	t_ldext		ext;
	int32_t		expb2;

	ext.n = n;
	expb2 = ext.f.exp + MIN_EXP - 1;
	*expb10 = log10_err(ext.f.exp - 16382, ext.f.mantissa);
	*numerator = ft_bigint_new(ext.f.mantissa);
	*denominator = ft_bigint_new(2);
	if (expb2 >= 0)
	{
		ft_bigint_lshift(numerator, expb2 + 1 + bias_pos(ext.f.mantissa));
		ft_bigint_lshift(denominator, bias_pos(ext.f.mantissa));
	}
	else
	{
		ft_bigint_lshift(numerator, 1 + bias_neg(ext.f.mantissa, expb2));
		ft_bigint_lshift(denominator, -expb2 + bias_neg(ext.f.mantissa, expb2));
	}
	if (*expb10 >= 0)
		ft_bigint_mulpow10(denominator, *expb10);
	else
		ft_bigint_mulpow10(numerator, -*expb10);
	return (0);
}

void			ft_ld2buf(char *buf, long double n)
{
	int32_t		expb10;
	t_bigint	numerator;
	t_bigint	denominator;
	size_t		i;

	init(n, &numerator, &denominator, &expb10);
	if (ft_bigint_cmp(&numerator, &denominator) <= 0)
		++expb10;
	else
		ft_bigint_mulpow10(&numerator, 1);
	i = 0;
	while (numerator.size)
	{
		buf[i] = '0' + ft_bigint_div(&numerator, &denominator, 9);
		ft_bigint_mulpow10(&numerator, 1);
		i++;
	}
	buf[i++] = 'e';
	char *exp = ft_itoa(expb10 - 1); // exp is the exponent of 0.xxxx so we substract one to displaz x.xxxx
	if (expb10 >= 0) buf[i++] = '+';
	ft_strcpy(buf + i, exp);
	ft_strdel(&exp);
}
