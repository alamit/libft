/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:55:20 by alamit            #+#    #+#             */
/*   Updated: 2019/04/04 07:23:57 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_math.h>
#include <inttypes.h>
#include <ft_string.h>

int		ft_conv_d(char *buf, const char *format, int64_t n)
{
	t_format	f;
	uint64_t	un;
	ssize_t		len;
	char		*start;

	start = buf;
	ft_format_parse(&f, format);
	if (n < 0)
		*(buf++) = '-';
	else if (ft_strchr(f.flag, '+'))
		*(buf++) = '+';
	else if(ft_strchr(f.flag, ' '))
		*(buf++) = ' ';
	un = ft_abs(n);
	len = ft_log10(un);
	while (f.precision-- > len)
		*(buf++) = '0';
	while (un)
	{
		buf[--len] = un % 10 + '0';
		un /= 10;
		start--;
	}
	return (buf - start);
}
