/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:55:47 by alamit            #+#    #+#             */
/*   Updated: 2019/04/01 16:18:47 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_string.h>
#include <ft_math.h>

static size_t	conv_len(t_format *f, t_f80_b10 *b10)
{
	size_t	int_len;
	size_t	frac_len;
	size_t	sign_len;

	if (b10->nan)
		return (ft_strlen(b10->nan(f->type < 'a')));
	sign_len = b10->sign || ft_strchr(f->flag, '+') || ft_strchr(f->flag, ' ');
	if (b10->inf)
		return (sign_len + ft_strlen(b10->inf(f->type < 'a')));
	int_len = b10->exp > 0 ? b10->exp : 1;
	frac_len = f->precision || ft_strchr(f->flag, '#')
		? 1 + f->precision : f->precision;
	return (sign_len + int_len + frac_len);
}

static int		prefix(t_buff *buff, t_format *f, t_f80_b10 *b10)
{
	int		zero_flag;
	size_t	padding;
	size_t	len;

	len = conv_len(f, b10);
	padding = f->field_width > len ? f->field_width - len : 0;
	zero_flag = (int)ft_strchr(f->flag, '0') && !b10->nan && !b10->inf;
	return ((!zero_flag && !ft_buffc(buff, ' ', padding))
		|| (!b10->nan && b10->sign && !ft_buffc(buff, '-', 1)
			&& ft_strchr(f->flag, '+') && !ft_buffc(buff, '+', 1)
			&& ft_strchr(f->flag, ' ') && !ft_buffc(buff, ' ', 1))
		|| (zero_flag && !ft_buffc(buff, '0', padding)));
}

int				ft_conv_f(t_buff *buff, const char *format, t_float80 n)
{
	t_f80_b10	b10;
	size_t		num_digits;
	t_format	f;

	if (!ft_format_parse(&f, format))
		return (0);
	f.precision = f.precision < 0 ? 6 : f.precision;
	ft_float80_b10(&b10, n);
	num_digits = 0;
	if (b10.get_digits)
		num_digits = b10.get_digits(&b10,
			(b10.exp > 0 ? b10.exp : 1) + f.precision);
	prefix(buff, &f, &b10);
	if (b10.nan)
		return (ft_buffs(buff, b10.nan(f.type < 'a')));
	if (b10.inf)
		return (ft_buffs(buff, b10.inf(f.type < 'a')));
	if (b10.exp > 0)
		return (!ft_buff(buff, b10.buf, b10.exp)
			|| ((f.precision || ft_strchr(f.flag, '#')) && !ft_buffc(buff, '.', 1))
			|| !ft_buff(buff, b10.buf + b10.exp, num_digits - b10.exp)
			|| !ft_buffc(buff, '0', b10.exp + f.precision - num_digits));
	return (!ft_buffc(buff, '0', 1)
		|| ((f.precision || ft_strchr(f.flag, '#')) && !ft_buffc(buff, '.', 1))
		|| !ft_buffc(buff, '0', ft_abs(b10.exp))
		|| !ft_buff(buff, b10.buf + 1, num_digits - 1)
		|| !ft_buffc(buff, '0', 1 + f.precision - num_digits));
}
