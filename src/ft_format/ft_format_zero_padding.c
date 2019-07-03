/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_zero_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:27:24 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 12:49:49 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

size_t	ft_format_zero_padding(t_format *f, size_t conv_len)
{
	if (f->field_width > conv_len && !ft_format_has_flag(f, '-')
		&& ft_format_has_flag(f, '0'))
		return (f->field_width - conv_len);
	return (0);
}