/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float80_b10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:32:51 by alamit            #+#    #+#             */
/*   Updated: 2019/07/02 15:53:36 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>
#include <ft_float.h>
#include <ft_float_params.h>
#include <stddef.h>
#include <ft_ctype.h>

#define LOG10_2 0.30102999566398119521373889472449L

/*
**	Estimation of logarithm base 10 of a long double with error.
**	The error is introduced to maximize:
**	- If expb2 >=0: Overestimate the log10.
**	- If expb2 < 0: Underestimate the log10.
**	The error is always 1 or 0.
*/

static int32_t	log10_err(t_f80_data *n_data)
{
	int32_t		hbit;
	int32_t		res;
	uint64_t	mantissa;

	hbit = 0;
	mantissa = n_data->mantissa;
	if (!mantissa)
		return (0);
	while (!(mantissa & (1ul << 63)))
	{
		++hbit;
		mantissa <<= 1;
	}
	res = (int32_t)((long double)(n_data->expb2 - hbit) * LOG10_2 - 0.69L);
	return (res >= 0 ? res + 1 : res);
}

// static void		init(t_f80_data *n, t_f80_b10 *b10)
// {
// 	b10->p = ft_bigint_new(n->mantissa);
// 	b10->q = ft_bigint_new(1l << 63);
// 	if (n->expb2 >= 0)
// 	{
// 		ft_bigint_lshift(&b10->p, n->expb2 - b10->exp);
// 		ft_bigint_mulpow5(&b10->q, b10->exp);
// 	}
// 	else
// 	{
// 		ft_bigint_mulpow5(&b10->p, -b10->exp);
// 		ft_bigint_lshift(&b10->q, b10->exp - n->expb2);
// 	}
// 	if (ft_bigint_cmp(&b10->p, &b10->q) <= 0)
// 		++b10->exp;
// 	else
// 		ft_bigint_mulpow10(&b10->p, 1);
// }

static uint8_t	round(t_f80_b10 *b10, uint8_t next)
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
	while (i-- && carry)
	{
		b10->decimal[i] += carry;
		carry = b10->decimal[i] > '9';
		b10->decimal[i] = carry ? b10->decimal[i] - 10 : b10->decimal[i];
	}
	b10->exp += carry;
	return (carry);
}

// static size_t	get_digits(t_f80_b10 *b10, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && b10->p.size)
// 	{
// 		b10->buf[i++] = '0' + ft_bigint_div(&b10->p, &b10->q, 9);
// 		ft_bigint_mulpow10(&b10->p, 1);
// 	}
// 	b10->exp = round(b10->buf, i, b10->exp, ft_bigint_div(&b10->p, &b10->q, 9));
// 	return (i);
// }

// void			ft_float80_b10(t_f80_b10 *b10, t_float80 n)
// {
// 	t_f80_data	n_data;

// 	n_data = ft_float80_extract(n);
// 	b10->sign = n_data.sign;
// 	b10->inf = NULL;
// 	b10->nan = NULL;
// 	b10->get_digits = NULL;
// 	if (n_data.type == INF)
// 		b10->inf = &ft_float_params_inf;
// 	else if (n_data.type == NAN)
// 		b10->nan = &ft_float_params_nan;
// 	else
// 	{
// 		b10->exp = log10_err(&n_data);
// 		init(&n_data, b10);
// 		b10->get_digits = &get_digits;
// 	}
// }

static void		compute(t_f80_b10 *b10, t_bigint *p, t_bigint *q)
{
	uint16_t	i;

	i = 0;
	if (b10->exp < 0 && !b10->sci)
		b10->decimal[i--] = '0';
	while ((b10->sci || i <= b10->exp) && p->size)
	{
		b10->decimal[i++] = ft_num2char(ft_bigint_div(p, q, 9));
		ft_bigint_mulpow10(p, 1);
		if (b10->sci)
			break;
	}
	b10->decimal[i++] = '\0';
	b10->dec_len = i;
	while (i < b10->precision + b10->exp && i < b10->precision && p->size)
	{
		b10->fractional[i++] = ft_num2char(ft_bigint_div(p, q, 9));
		ft_bigint_mulpow10(p, 1);
	}
	b10->fractional[i++] = '\0';
	b10->frac_len = i;
	b10->carry = round(b10, ft_bigint_div(p, q, 9));
}

void			ft_float80_b10(t_f80_b10 *b10, t_float80 n, size_t pre)
{
	t_f80_data	f_data;
	t_bigint	p;
	t_bigint	q;

	f_data = ft_float80_extract(n);
	b10->sign = f_data.sign;
	b10->exp = log10_err(&f_data);
	b10->precision = pre;
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
