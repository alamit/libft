/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfconv_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:22:31 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:20:24 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <stdarg.h>
#include <inttypes.h>

int		ft_vfconv_d(t_buff *buf, t_format *f, va_list ap)
{
	int64_t		val;
	int8_t		lenmod;

	lenmod = ft_format_lenmod(f);
	if (lenmod == -2)
		val = (int64_t)(char)va_arg(ap, int);
	else if (lenmod == -1)
		val = (int64_t)(short)va_arg(ap, int);
	else if (lenmod == 0)
		val = (int64_t)(int)va_arg(ap, int);
	else if (lenmod == 1)
		val = (int64_t)(long)va_arg(ap, long);
	else if (lenmod == 2)
		val = (int64_t)(long long)va_arg(ap, long long);
	else
		return (-1);
	return (ft_fconv_d(buf, f, val));
}
