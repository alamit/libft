/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:18:19 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:19:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>

int		ft_conv_c(t_buff *buf, const char *format, int c)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_c(buf, &f, c));
	return (-1)
}
