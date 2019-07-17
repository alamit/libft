/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_left_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:13:42 by alamit            #+#    #+#             */
/*   Updated: 2019/07/16 14:36:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_string.h>
#include <ft_math.h>

size_t	ft_format_left_padding(t_format *f, size_t conv_len, char sign, const char *prefix)
{
	conv_len += (sign != 0) + (prefix ? ft_strlen(prefix) : 0);
	if (f->field_width > conv_len && !ft_format_has_flag(f, '-')
		&& !ft_format_has_flag(f, '0'))
		return (ft_submin0(f->field_width, conv_len));
	return (0);
}
