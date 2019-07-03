/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:16:45 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:20:58 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <wchar.h>
#include <ft_format.h>

int		ft_conv_ls(t_buff *buf, const char *format, wchar_t *ws)
{
	t_format	f;

	if (ft_format_parse(&f, format) >= 0)
		return (ft_fconv_ls(buf, &f, ws));
	return (-1)
}
