/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float80_b10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:32:51 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 12:26:12 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>
#include <ft_float.h>
#include <stddef.h>
#include <ft_ctype.h>
#include <ft_math.h>

#define LOG10_2 0.30102999566398119521373889472449L

/*
**	Estimation of logarithm base 10 of a long double with error.
**	The error is introduced to maximize:
**	- If expb2 >=0: Overestimate the log10.
**	- If expb2 < 0: Underestimate the log10.
**	The error is always 1 or 0.
*/

static int32_t	log10_err(t_f80_data *data)
{
	int32_t		hbit;
	int32_t		res;
	uint64_t	mantissa;

	hbit = 0;
	mantissa = data->mantissa;
	if (!mantissa)
		return (1);
	while (!(mantissa & (1ul << 63)))
	{
		++hbit;
		mantissa <<= 1;
	}
	if (data->expb2 - hbit == 0)
		return (0);
	res = (int32_t)((t_float80)(ft_abs(data->expb2) - hbit) * LOG10_2 - 0.69L);
	res++;
	return (data->expb2 >= 0 ? res : -res);
}

static uint8_t	ft_round(t_f80_b10 *b10, uint8_t next)
{
	size_t	i;
	uint8_t	carry;

	i = b10->frac_len;
	carry = next > 5 || (next == 5 && b10->fractional[i - 1] - '0' % 2) ? 1 : 0;
	while (i-- && carry)
	{
		b10->fractional[i] += carry;
		carry = b10->fractional[i] > '9';
		b10->fractional[i] = carry
			? b10->fractional[i] - 10 : b10->fractional[i];
	}
	i = b10->dec_len;
	while (i-- && carry && (b10->sci || b10->exp >= 0))
	{
		b10->decimal[i] += carry;
		carry = b10->decimal[i] > '9';
		b10->decimal[i] = carry ? b10->decimal[i] - 10 : b10->decimal[i];
	}
	b10->exp += carry;
	return (carry);
}

static void		compute(t_f80_b10 *b10, t_bigint *p, t_bigint *q)
{
	uint16_t	i;
	uint16_t	start;

	i = 0;
	if (b10->exp < 1 && !b10->sci)
		b10->decimal[i++] = '0';
	while ((b10->sci || i < b10->exp))
	{
		b10->decimal[i++] = ft_num2char(ft_bigint_div(p, q, 9));
		ft_bigint_mulpow10(p, 1);
		if (b10->sci)
			break ;
	}
	b10->dec_len = i;
	i = (b10->sci || b10->exp >= 0 ? 0 : -b10->exp);
	start = i;
	while (i < b10->precision && p->size)
	{
		b10->fractional[i++ - start] = ft_num2char(ft_bigint_div(p, q, 9));
		ft_bigint_mulpow10(p, 1);
	}
	b10->frac_len = i - start;
	b10->carry = ft_round(b10, ft_bigint_div(p, q, 9));
}

void			b10_init(t_f80_b10 *b10, t_f80_data *f_data, size_t pre,
	uint8_t sci)
{
	b10->sign = f_data->sign;
	b10->nan = 0;
	b10->inf = 0;
	if (f_data->type == NAN)
		b10->nan = 1;
	else if (f_data->type == INF)
		b10->inf = 1;
	b10->exp = log10_err(f_data);
	b10->precision = pre;
	b10->sci = sci;
}

void			ft_float80_b10(t_f80_b10 *b10, t_float80 n, size_t pre,
	uint8_t sci)
{
	t_f80_data	f_data;
	t_bigint	p;
	t_bigint	q;

	f_data = ft_float80_extract(n);
	b10_init(b10, &f_data, pre, sci);
	if (b10->inf || b10->nan)
		return ;
	p = ft_bigint_new(f_data.mantissa);
	q = ft_bigint_new(1ll << 63);
	if (f_data.expb2 >= 0)
	{
		ft_bigint_lshift(&p, f_data.expb2 - b10->exp);
		ft_bigint_mulpow5(&q, b10->exp);
	}
	else
	{
		ft_bigint_mulpow5(&p, -b10->exp);
		ft_bigint_lshift(&q, b10->exp - f_data.expb2);
	}
	if (ft_bigint_cmp(&p, &q) <= 0)
		++b10->exp;
	else
		ft_bigint_mulpow10(&p, 1);
	compute(b10, &p, &q);
}
