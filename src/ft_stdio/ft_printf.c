/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:04:01 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 11:04:37 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>

int		ft_printf(const char *format, ...)
{
	int			res;
	va_list		ap;

	va_start(ap, format);
	res = ft_vprintf(format, ap);
	va_end(ap);
	return (res);
}
