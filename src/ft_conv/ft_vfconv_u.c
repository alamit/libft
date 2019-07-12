/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfconv_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:26:57 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:36:42 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <stdarg.h>
#include <inttypes.h>

int		ft_vfconv_u(t_buff *buf, t_format *f, va_list ap)
{
	uint64_t	val;
	int8_t		lenmod;

	lenmod = ft_format_lenmod(f);
	if (lenmod == -2)
		val = (uint64_t)(unsigned char)va_arg(ap, unsigned int);
	else if (lenmod == -1)
		val = (uint64_t)(unsigned short)va_arg(ap, unsigned int);
	else if (lenmod == 0)
		val = (uint64_t)(unsigned int)va_arg(ap, unsigned int);
	else if (lenmod == 1)
		val = (uint64_t)(unsigned long)va_arg(ap, unsigned long);
	else if (lenmod == 2)
		val = (uint64_t)(unsigned long long)va_arg(ap, unsigned long long);
	else
		return (-1);
	return (ft_fconv_u(buf, f, val));
}
