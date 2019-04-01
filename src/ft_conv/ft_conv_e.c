/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:43:33 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 21:44:43 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_string.h>
#include <ft_math.h>

static int		length_mod(t_format *f, t_float80 *n)
{
	if ((f->length_mod[0] == 'l' || !f->length_mod[0]) && !f->length_mod[1])
		*n = (t_float64)*n;
	else if (f->length_mod[0] != 'L' || f->length_mod[1])
		return (0);
	return (1);
}

static size_t	conv_len(t_format *f, t_f80_b10 *b10)
{
	size_t	exp_len;
	size_t	int_len;
	size_t	frac_len;
	size_t	sign_len;

	if (b10->nan)
		return (ft_strlen(b10->nan(f->type < 'a')));
	sign_len = b10->sign || ft_strchr(f->flag, '+') || ft_strchr(f->flag, ' ');
	if (b10->inf)
		return (sign_len + ft_strlen(b10->inf(f->type < 'a')));
	exp_len = ft_log10(ft_abs(b10->exp)) + 2;
	int_len = 1;
	frac_len = f->precision || ft_strchr(f->flag, '#')
		? 1 + f->precision : f->precision;
	return (sign_len + int_len + frac_len + (exp_len < 4 ? 4 : exp_len));
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

int				ft_conv_e(t_buff *buff, const char *format, t_float80 n)
{
	t_f80_b10	b10;
	size_t		num_digits;
	t_format	f;

	if (!ft_format_parse(&f, format) || !length_mod(&f, &n))
		return (0);
	f.precision = f.precision < 0 ? 6 : f.precision;
	ft_float80_b10(&b10, n);
	prefix(buff, &f, &b10);
	if (b10.nan)
		return (ft_buffs(buff, b10.nan(f.type < 'a')));
	if (b10.inf)
		return (ft_buffs(buff, b10.inf(f.type < 'a')));
	num_digits = b10.get_digits(&b10, 1 + f.precision);
	return (!ft_buff(buff, b10.buf, 1)
		|| ((f.precision || ft_strchr(f.flag, '#')) && !ft_buffc(buff, '.', 1))
		|| !ft_buff(buff, b10.buf + 1, num_digits - 1)
		|| !ft_buffc(buff, '0', 1 + f.precision - num_digits)
		|| !ft_buffc(buff, f.type, 1)
		|| !ft_conv_d(buff, "%+.2d", b10.exp - 1));
}
