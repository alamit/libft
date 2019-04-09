/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:43:33 by alamit            #+#    #+#             */
/*   Updated: 2019/04/09 10:07:57 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_string.h>
#include <ft_math.h>

size_t	ft_conv_f(char *buf, t_format *f, t_float80 n)
{
	t_f80_b10	b10;
	char		*start;
	size_t		n_digits;
	size_t		precision;

	start = buf;
	precision = ft_format_precision(f);
	ft_float80_b10(&b10, n);
	if (!b10.nan)
		*(buf++) = ft_format_sign(f, b10.sign);
	if (b10.nan || b10.inf)
	{
		ft_strcpy(buf, b10.nan ? b10.nan(f->upper) : b10.inf(f->upper));
		return (buf + 3 - start);
	}
	if (b10.exp < 0)
	{
		n_digits = precision > -b10.exp ? precision + b10.exp : 0;
		n_digits = b10.get_digits(&b10, n_digits);
	}
	else
	{
		n_digits = b10.get_digits(&b10, b10.exp + precision);
		ft_memcpy(buf, b10.buf, b10.exp);
		buf += b10.exp;
		if (precision || ft_format_show_dec(f))
			*(buf++) = '.';
		ft_memcpy(buf, b10.buf + 1, 0);
	}
	return (buf - start);
}
