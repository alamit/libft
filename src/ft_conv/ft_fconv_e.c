/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:46:39 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:09:47 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_math.h>
#include <ft_format.h>
#include <ft_buff.h>
#include <stddef.h>

static size_t	conv_len(t_f80_b10 *b10, t_format *f)
{
	if (b10->inf || b10->nan)
		return (3);
	return (b10->dec_len + b10->precision
		+ (b10->precision > 0 || ft_format_has_flag(f, '#'))
		+ 2 + ft_log10(ft_abs(b10->exp)));
}

static int		convert(t_buff *buf, t_format *f, t_f80_b10 *b10)
{
	if (!b10->carry && !ft_buff(buf, b10->decimal, b10->dec_len))
		return (-1);
	else if (b10->carry && !ft_buffc(buf, '1', 1))
		return (-1);
	if ((b10->precision || ft_format_has_flag(f, '#'))
		&& !ft_buffc(buf, '.', 1))
		return (-1);
	if (b10->carry && !ft_buff(buf, b10->decimal, b10->dec_len))
		return (-1);
	if (!ft_buff(buf, b10->fractional, ft_submin0(b10->frac_len, b10->carry))
		|| !ft_buffc(buf, '0', ft_submin0(b10->precision, b10->frac_len))
		|| !ft_buffc(buf, f->upper ? 'E' : 'e', 1))
		return (-1);
	return (ft_conv_d(buf, "%+.2d", b10->exp - 1));
}

int				ft_fconv_e(t_buff *buf, t_format *f, t_float80 n)
{
	t_f80_b10	b10;
	size_t		len;

	ft_float80_b10(&b10, n, ft_format_precision(f), 1);
	if (b10.nan)
		f->flags = f->flags & ~0x04 & ~0x08;
	if (b10.inf || b10.nan)
		f->flags &= ~0x02;
	len = conv_len(&b10, f);
	if (!ft_buffc(buf, ' ',
		ft_format_left_padding(f, len, ft_format_sign(f, b10.sign), NULL))
		|| (ft_format_sign(f, b10.sign)
			&& !ft_buffc(buf, ft_format_sign(f, b10.sign), 1)))
		return (-1);
	if (!ft_buffc(buf, '0',
		ft_format_zero_padding(f, len, ft_format_sign(f, b10.sign), NULL))
		|| (b10.nan && !ft_buffs(buf, f->upper ? "NAN" : "nan"))
		|| (b10.inf && !ft_buffs(buf, f->upper ? "INF" : "inf")))
		return (-1);
	else if (!b10.inf && !b10.nan && convert(buf, f, &b10) < 0)
		return (-1);
	if (!ft_buffc(buf, ' ',
		ft_format_right_padding(f, len, ft_format_sign(f, b10.sign), NULL)))
		return (-1);
	return (0);
}
