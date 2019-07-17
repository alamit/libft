/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_zero_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:27:24 by alamit            #+#    #+#             */
/*   Updated: 2019/07/17 03:08:03 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_string.h>
#include <ft_math.h>

size_t	ft_format_zero_padding(t_format *f, size_t conv_len, char sign,
	const char *prefix)
{
	size_t	prec_pad;

	prec_pad = (ft_strchr("diouxbp", f->type) && f->precision)
		? ft_submin0(f->precision, conv_len) : 0;
	if (!ft_format_has_flag(f, '-') && ft_format_has_flag(f, '0'))
		prec_pad += ft_submin0(f->field_width,
			conv_len + prec_pad + (sign != 0)
				+ (prefix ? ft_strlen(prefix) : 0));
	return (prec_pad);
}
