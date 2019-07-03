/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:46:39 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 10:56:58 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_math.h>
#include <ft_format.h>
#include <ft_buff.h>

static size_t	conv_len(t_f80_b10 *b10, t_format *f)
{
	return (b10->dec_len + b10->precision
		+ (b10->precision > 0 || ft_format_has_flag(f, '#'))
		+ 2 + ft_log10(ft_abs(b10->exp))
		+ (ft_format_sign(f, b10->sign) != '\0'));
}

int				ft_fconv_e(t_buff *buf, t_format *f, t_float80 n)
{
	t_f80_b10	b10;
	size_t		len;

	ft_float80_b10(&b10, n, ft_format_precision(&f));
	len = conv_len(&b10, &f);
	ft_buffc(buf, ' ', ft_format_left_padding(&f, len));
	if (ft_format_sign(&f, b10.sign))
		ft_buffc(buf, ft_format_sign(&f, b10.sign), 1);
	ft_buffc(buf, '0', ft_format_zero_padding(&f, len));
	if (!b10.carry)
		ft_buffs(buf, b10.decimal);
	if (b10.precision || ft_format_has_flag(&f, '#'))
		ft_buffc(buf, '.', 1);
	if (b10.carry)
		ft_buffs(buf, b10.decimal);
	ft_buffs(buf, b10.fractional);
	ft_buffc(buf, '0', b10.precision - b10.frac_len);
	ft_buffc(buf, f.upper ? 'e' : 'E', 1);
	return (ft_conv_d(buf, "%+.2d", b10.exp - 1));
}
