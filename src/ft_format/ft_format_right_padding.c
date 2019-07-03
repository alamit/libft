/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_right_padding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:30:20 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 12:49:44 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

size_t	ft_format_right_padding(t_format *f, size_t conv_len)
{
	if (f->field_width > conv_len && ft_format_has_flag(f, '-'))
		return (f->field_width - conv_len);
	return (0);
}