/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:55:20 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 20:19:13 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_math.h>
#include <inttypes.h>
#include <ft_string.h>

int		ft_conv_d(t_buff *buff, const char *format, int64_t n)
{
	t_format	f;
	char 		buf[256];
	uint64_t	un;
	size_t		i;

	ft_format_parse(&f, format);
	i = 256;
	un = ft_abs(n);
	while (un)
	{
		buf[--i] = un % 10 + '0';
		un /= 10;
		f.precision = f.precision ? f.precision - 1 : f.precision;
	}
	if (n < 0)
		ft_buffc(buff, '-', 1);
	else if (ft_strchr(f.flag, '+'))
		ft_buffc(buff, '+', 1);
	else if(ft_strchr(f.flag, ' '))
		ft_buffc(buff, ' ', 1);
	ft_buffc(buff, '0', f.precision);
	ft_buff(buff, buf + i, 256 - i);
	return (1);
}
