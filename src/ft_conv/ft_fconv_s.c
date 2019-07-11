/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:26:22 by alamit            #+#    #+#             */
/*   Updated: 2019/07/11 17:14:22 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>
#include <ft_string.h>

int		ft_fconv_s(t_buff *buf, t_format *f, char *s)
{
	size_t	len;

	s = s ? s : "(null)";
	len = ft_strlen(s);
	len = len > f->precision ? f->precision : len;
	ft_buffc(buf, ' ', ft_format_left_padding(f, len));
	ft_buffc(buf, '0', ft_format_zero_padding(f, len));
	ft_buff(buf, s, len);
	ft_buffc(buf, ' ', ft_format_right_padding(f, len));
	return (0);
}
