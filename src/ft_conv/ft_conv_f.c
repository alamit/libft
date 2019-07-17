/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:43:33 by alamit            #+#    #+#             */
/*   Updated: 2019/07/16 17:42:53 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_float.h>
#include <ft_format.h>
#include <ft_buff.h>

int		ft_conv_f(t_buff *buf, const char *format, t_float80 n)
{
	t_format	f;

	if (ft_format_parse(&f, format))
		return (ft_fconv_f(buf, &f, n));
	return (-1);
}
