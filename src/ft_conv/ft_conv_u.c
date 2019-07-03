/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:20:05 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:20:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <inttypes.h>
#include <ft_format.h>

int		ft_conv_u(t_buff *buf, const char *format, uint64_t n)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_u(buf, &f, n));
	return (-1)
}
