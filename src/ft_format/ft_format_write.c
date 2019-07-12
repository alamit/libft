/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:31:50 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:51:32 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>
#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_ctype.h>
#include <stddef.h>

static int (* const conv[26])(t_buff *, t_format *, va_list) = {
	NULL,
	ft_vfconv_b,
	ft_vfconv_c,
	ft_vfconv_d,
	ft_vfconv_e,
	ft_vfconv_f,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	ft_vfconv_o,
	NULL,
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

int			ft_format_write(t_format *f, t_buff *buff, va_list ap)
{
	if (f->type - 'a' < 0 || f->type - 'a' > 25 || !conv[f->type - 'a'])
		return (0);
	return (conv[f->type - 'a'](buff, f, ap));
}
