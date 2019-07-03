/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:14:38 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:17:05 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <wchar.h>
#include <ft_format.h>

int		ft_conv_lc(t_buff *buf, const char *format, wint_t wc)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_lc(buf, &f, wc));
	return (-1)
}
