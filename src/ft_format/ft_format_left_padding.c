/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_left_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:13:42 by alamit            #+#    #+#             */
/*   Updated: 2019/07/02 16:28:25 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

size_t	ft_format_left_padding(t_format *f, size_t conv_len)
{
	if (f->field_width > conv_len && !ft_format_has_flag(f, '-')
		&& !format_has_flag(f, '0'))
		return (f->field_width - conv_len);
	return (0);
}
