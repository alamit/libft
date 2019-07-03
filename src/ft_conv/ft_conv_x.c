/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:20:21 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:51:21 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <inttypes.h>
#include <ft_format.h>

int		ft_conv_x(t_buff *buf, const char *format, uint64_t n)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_x(buf, &f, n));
	return (-1);
}
