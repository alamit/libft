/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_u_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:58:08 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:15:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>
#include <inttypes.h>
#include <ft_format.h>
#include <ft_ctype.h>
#include <ft_buff.h>
#include <ft_string.h>

static const char	*g_p2_alphabet[] = {
	"01",
	"0123",
	"01234567",
	"0123456789abcdef"
};

static size_t		zp(t_format *f, size_t len, const char *prefix)
{
	return (ft_format_zero_padding(f, len, 0, prefix));
}

static int			pre_padding(t_buff *buf, t_format *f, size_t len,
	const char *prefix)
{
	if (!ft_buffc(buf, ' ',
			ft_format_left_padding(f, len + zp(f, len, prefix), 0, prefix))
		|| !ft_buffs(buf, prefix)
		|| !ft_buffc(buf, '0', zp(f, len, prefix)))
		return (-1);
	return (0);
}

int					ft_fconv_u_base(t_buff *buf, t_format *f, uint64_t n,
	uint8_t expb2)
{
	const char	*prefix;
	size_t		len;
	size_t		pbase;
	size_t		log;

	log = ft_submin0(ft_log(n, 1ll << expb2), 1);
	len = n ? log + 1 : 0;
	prefix = ft_format_prefix(f, len);
	if (pre_padding(buf, f, len, prefix) < 0)
		return (-1);
	pbase = n ? 1ll << (expb2 * log) : 0;
	while (pbase)
	{
		if (!ft_buffc(buf, f->upper
				? ft_toupper(g_p2_alphabet[expb2 - 1][n / pbase])
				: g_p2_alphabet[expb2 - 1][n / pbase], 1))
			return (-1);
		n %= pbase;
		pbase /= 1ll << expb2;
	}
	if (!ft_buffc(buf, ' ',
			ft_format_right_padding(f, len + zp(f, len, prefix), 0, prefix)))
		return (-1);
	return (0);
}
