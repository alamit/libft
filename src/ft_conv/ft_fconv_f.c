/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:52:57 by alamit            #+#    #+#             */
/*   Updated: 2019/07/17 07:03:40 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_float.h>
#include <ft_buff.h>
#include <ft_math.h>
#include <stddef.h>

static size_t	conv_len(t_f80_b10 *b10, t_format *f)
{
	if (b10->nan || b10->inf)
		return (3);
	return (b10->dec_len + b10->precision
		+ (b10->precision > 0 || ft_format_has_flag(f, '#'))
		+ b10->carry);
}

int		ft_fconv_f(t_buff* buf, t_format *f, t_float80 n)
{
	t_f80_b10	b10;
	size_t		len;

	ft_float80_b10(&b10, n, ft_format_precision(f), 0);
	if (b10.nan)
		f->flags = f->flags & ~0x04 & ~0x08;
	if (b10.inf || b10.nan)
		f->flags &= ~0x02;
	len = conv_len(&b10, f);
	ft_buffc(buf, ' ', ft_format_left_padding(f, len, ft_format_sign(f, b10.sign), NULL));
	if (ft_format_sign(f, b10.sign))
		ft_buffc(buf, ft_format_sign(f, b10.sign), 1);
	ft_buffc(buf, '0', ft_format_zero_padding(f, len, ft_format_sign(f, b10.sign), NULL));
	if (b10.nan)
		ft_buffs(buf, f->upper ? "NAN" : "nan");
	else if (b10.inf)
		ft_buffs(buf, f->upper ? "INF" : "inf");
	else
	{
		if (b10.carry && b10.exp >= 0)
			ft_buffc(buf, '1', 1);
		ft_buff(buf, b10.decimal, b10.dec_len);
		if (b10.precision || ft_format_has_flag(f, '#'))
			ft_buffc(buf, '.', 1);
		if (b10.exp < 0)
		{
			ft_buffc(buf, '0', ft_min(-b10.exp, b10.precision));
			ft_buffc(buf, '1', b10.carry);
		}
		ft_buff(buf, b10.fractional, b10.frac_len);
		if (b10.exp < 0)
			ft_buffc(buf, '0',
				ft_submin0(ft_submin0(b10.precision, b10.frac_len + b10.carry), -b10.exp));
		else
			ft_buffc(buf, '0', ft_submin0(b10.precision, b10.frac_len));
	}
	ft_buffc(buf, ' ', ft_format_right_padding(f, len, ft_format_sign(f, b10.sign), NULL));
	return (0);
}
