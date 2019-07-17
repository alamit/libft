/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_set_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:00:27 by alamit            #+#    #+#             */
/*   Updated: 2019/07/17 03:07:31 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_string.h>
#include <inttypes.h>

void	ft_format_set_precision(t_format *f, int32_t precision)
{
	if (precision < 0)
	{
		if (ft_strchr("diouxbp", f->type))
			f->precision = 1;
		else if (f->type == 's')
			f->precision = UINT32_MAX;
		else
			f->precision = 6;
	}
	else
	{
		f->precision = precision;
		if (ft_strchr("diouxbp", f->type))
			f->flags &= ~0x02;
	}
}
