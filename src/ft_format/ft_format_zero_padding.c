/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_zero_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:27:24 by alamit            #+#    #+#             */
/*   Updated: 2019/07/04 17:22:26 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_string.h>

size_t	ft_format_zero_padding(t_format *f, size_t conv_len)
{
	if (ft_strchr("diouxb", f->type) && f->precision)
		return (f->precision - conv_len);
	else if (f->field_width > conv_len && !ft_format_has_flag(f, '-')
		&& ft_format_has_flag(f, '0'))
		return (f->field_width - conv_len);
	return (0);
}
