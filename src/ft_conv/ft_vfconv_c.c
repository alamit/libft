/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfconv_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:20:47 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:39:26 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <stdarg.h>

int		ft_vfconv_c(t_buff *buf, t_format *f, va_list ap)
{
	int		val;

	if (ft_format_lenmod(f) != 0)
		return (-1);
	val = (int)va_arg(ap, int);
	return (ft_fconv_c(buf, f, val));
}
