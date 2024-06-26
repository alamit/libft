/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:23:25 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:18:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>
#include <stddef.h>

int		ft_fconv_c(t_buff *buf, t_format *f, int c)
{
	if (!ft_buffc(buf, ' ', ft_format_left_padding(f, 1, 0, NULL))
		|| !ft_buffc(buf, '0', ft_format_zero_padding(f, 1, 0, NULL))
		|| !ft_buffc(buf, (unsigned char)c, 1)
		|| !ft_buffc(buf, ' ', ft_format_right_padding(f, 1, 0, NULL)))
		return (-1);
	return (0);
}
