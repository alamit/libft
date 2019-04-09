/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:43:33 by alamit            #+#    #+#             */
/*   Updated: 2019/04/05 18:36:54 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_string.h>
#include <ft_math.h>

size_t				ft_conv_e(char *buf, t_format *f, t_float80 n)
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
	n_digits = b10.get_digits(&b10, precision);
	f->precision -= n_digits;
	*(buf++) = b10.buf[0];
	if (precision || ft_format_show_dec(f))
		*(buf++) = '.';
	ft_memcpy(buf, b10.buf + 1, n_digits - 1);
	buf += n_digits - 1;
	while (precision--)
		*(buf++) = '0';
	*(buf++) = f->upper ? 'E' : 'e';
	buf += ft_conv_d(buf, "%+.2d", b10.exp - 1);
	return (buf - start);
}
