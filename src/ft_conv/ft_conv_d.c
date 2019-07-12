/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:55:20 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:05:51 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <inttypes.h>
#include <ft_format.h>

int		ft_conv_d(t_buff *buf, const char *format, int64_t n)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_d(buf, &f, n));
	return (-1);
}
