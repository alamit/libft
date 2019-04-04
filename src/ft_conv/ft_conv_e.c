/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:43:33 by alamit            #+#    #+#             */
/*   Updated: 2019/04/04 08:58:01 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_string.h>
#include <ft_math.h>

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

static char		*prefix(char *buf, t_format *f, t_f80_b10 *b10)
{
	int		zero_flag;
	size_t	padding;
	size_t	len;

	len = conv_len(f, b10);
	padding = f->field_width > len ? f->field_width - len : 0;
	zero_flag = (int)ft_strchr(f->flag, '0') && !b10->nan && !b10->inf;
	if (!zero_flag)
		buf = ft_memset(buf, ' ', padding) + padding;
	if (!b10->nan)
	{
		if (b10->sign)
			buf = ft_memset(buf, '-', 1) + 1;
		else if (ft_strchr(f->flag, '+'))
			buf = ft_memset(buf, '+', 1) + 1;
		else if (ft_strchr(buf, ' '))
			buf = ft_memset(buf, ' ', 1);
	}
	if (zero_flag)
		buf = ft_memset(buf, '0', padding) + padding;
	return (buf);
}

size_t				ft_conv_e(char *buf, const char *format, t_float80 n)
{
	t_f80_b10	b10;
	t_format	f;
	char		*start;
	ssize_t		i;

	start = buf;
	if (!ft_format_parse(&f, format))
		return (0);
	f.precision = f.precision < 0 ? 6 : f.precision;
	ft_float80_b10(&b10, n);
	buf = prefix(buf, &f, &b10);
	if (b10.nan || b10.inf)
	{
		ft_strcpy(buf, b10.nan ? b10.nan(f.type < 'a') : b10.inf(f.type < 'a'));
		return (buf + 3 - start);
	}
	*(buf++) = b10.get_digit(&b10);
	if (f.precision || ft_strchr(f.flag, '#'))
		*(buf++) = '.';
	i = 0;
	while (i++ < f.precision)
		*(buf++) = b10.get_digit(&b10);
	buf = b10.round(buf, f.precision + 2, &b10);
	*(buf++) = f.type;
	buf += ft_conv_d(buf, "%+.2d", b10.exp - 1);
	return (buf - start);
}
