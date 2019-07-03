/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:19:32 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:20:46 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>

int		ft_conv_s(t_buff *buf, const char *format, char *s)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_s(buf, &f, s));
	return (-1)
}
