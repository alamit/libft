/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:18:19 by alamit            #+#    #+#             */
/*   Updated: 2019/07/16 17:42:34 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>

int		ft_conv_c(t_buff *buf, const char *format, int c)
{
	t_format	f;

	if (ft_format_parse(&f, format))
		return (ft_fconv_c(buf, &f, c));
	return (-1);
}
