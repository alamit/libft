/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:31:50 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 12:21:11 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_ctype.h>
#include <stddef.h>

static int (*const g_conv[26])(t_buff *, t_format *, va_list) = {
	NULL,
	ft_vfconv_b,
	ft_vfconv_c,
	ft_vfconv_d,
	ft_vfconv_e,
	ft_vfconv_f,
	NULL,
	NULL,
	ft_vfconv_d,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_vfconv_o,
	ft_vfconv_x,
	NULL,
	NULL,
	ft_vfconv_s,
	NULL,
	ft_vfconv_u,
	NULL,
	NULL,
	ft_vfconv_x,
	NULL,
	NULL
};

int			ft_format_write(t_buff *buf, t_format *f, va_list ap)
{
	if (f->type == '%')
		return (ft_fconv_c(buf, f, '%'));
	else if (f->type - 'a' < 0 || f->type - 'a' > 25 || !g_conv[f->type - 'a'])
		return (0);
	return (g_conv[f->type - 'a'](buf, f, ap));
}
