/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfconv_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:27:06 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:37:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <stdarg.h>

int		ft_vfconv_s(t_buff *buf, t_format *f, va_list ap)
{
	char	*val;

	if (ft_format_lenmod(f) != 0)
		return (-1);
	val = (char *)va_arg(ap, char *);
	return (ft_fconv_s(buf, f, val));
}
