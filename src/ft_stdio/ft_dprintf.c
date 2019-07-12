/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:00:09 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 11:03:50 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>

int		ft_dprintf(int fd, const char *format, ...)
{
	int			res;
	va_list		ap;

	va_start(ap, format);
	res = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (res);
}
