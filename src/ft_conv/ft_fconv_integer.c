/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 08:59:22 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 11:58:08 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>
#include <inttypes.h>
#include <ft_format.h>
#include <ft_ctype.h>
#include <ft_buff.h>

static size_t	conv_len(size_t expb10, t_format *f, uint8_t sign)
{
	return (expb10 + (ft_format_sign(f, sign) != '\0'));
}

int				ft_fconv_integer(t_buff *buf, t_format *f, uint64_t n,
	uint8_t sign)
{
	size_t		p10;
	size_t		len;
	size_t		expb10;

	expb10 = ft_log10(n) - 1;
	len = conv_len(expb10, f, sign);
	ft_buffc(buf, ' ',
		ft_format_left_padding(f, len + ft_submin0(f->precision, expb10)));
	if (sign)
		ft_buffc(buf, ft_format_sign(f, sign), 1);
	ft_buffc(buf, '0', ft_format_zero_padding(f, len));
	p10 = ft_ipow(10, expb10);
	while (p10)
	{
		ft_buffc(buf, ft_num2char(n / p10), 1);
		n %= p10;
		p10 /= 10;
	}
	ft_buffc(buf, ' ',
		ft_format_right_padding(f, len + ft_submin0(f->precision, expb10)));
	return (0);
}
