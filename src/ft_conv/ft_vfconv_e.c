/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfconv_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:23:41 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:37:13 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <stdarg.h>
#include <ft_float.h>

int		ft_vfconv_e(t_buff *buf, t_format *f, va_list ap)
{
	t_float80	val;
	int8_t		lenmod;

	lenmod = ft_format_lenmod(f);
	if (lenmod == 0 || lenmod == 1)
		val = (t_float80)(double)va_arg(ap, double);
	else if (lenmod == 2)
		val = (t_float80)(long double)va_arg(ap, long double);
	else
		return (-1);
	return (ft_fconv_e(buf, f, val));
}
