/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:23:25 by alamit            #+#    #+#             */
/*   Updated: 2019/07/16 14:10:51 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>
#include <stddef.h>

int		ft_fconv_c(t_buff *buf, t_format *f, int c)
{
	ft_buffc(buf, ' ', ft_format_left_padding(f, 1, 0, NULL));
	ft_buffc(buf, '0', ft_format_zero_padding(f, 1, 0, NULL));
	ft_buffc(buf, (unsigned char)c, 1);
	ft_buffc(buf, ' ', ft_format_right_padding(f, 1, 0, NULL));
	return (0);
}
