/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_u_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:58:08 by alamit            #+#    #+#             */
/*   Updated: 2019/07/05 15:43:05 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>
#include <inttypes.h>
#include <ft_format.h>
#include <ft_ctype.h>
#include <ft_buff.h>
#include <ft_string.h>

const char		*p2_alphabet[] = {
	"01",
	"0123",
	"01234567",
	"0123456789abcdef"
};

size_t			conv_len(t_format *f, size_t log)
{
	return (ft_strlen(ft_format_prefix(f)) + log);
}

int				ft_fconv_u_base(t_buff *buf, t_format *f, uint64_t n,
	uint8_t expb2)
{
	uint64_t	base;
	size_t		len;
	size_t		pbase;
	size_t		log;

	base = 1ll << expb2;
	log = ft_log(n, base);
	len = conv_len(f, log);
	ft_buffc(buf, ' ',
		ft_format_left_padding(f, len + ft_submin0(f->precision, log)));
	ft_buffs(buf, ft_format_prefix(f));
	ft_buffc(buf, '0', ft_format_zero_padding(f, log ? log : 1));
	pbase = 1ll << (expb2 * ft_submin0(log , 1));
	while (pbase)
	{
		ft_buffc(buf, f->upper
			? ft_toupper(p2_alphabet[expb2 - 1][n / pbase])
			: p2_alphabet[expb2 - 1][n / pbase], 1);
		n %= pbase;
		pbase /= base;
	}
	ft_buffc(buf, ' ',
		ft_format_right_padding(f, len + ft_submin0(f->precision, log)));
	return (0);
}
