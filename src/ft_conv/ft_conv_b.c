/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:17:26 by alamit            #+#    #+#             */
/*   Updated: 2019/07/16 17:42:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <inttypes.h>
#include <ft_format.h>

int		ft_conv_b(t_buff *buf, const char *format, uint64_t n)
{
	t_format	f;

	if (ft_format_parse(&f, format))
		return (ft_fconv_b(buf, &f, n));
	return (-1);
}
