/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:04:29 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 11:05:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>

int		ft_sprintf(char **str, const char *format, ...)
{
	int			res;
	va_list		ap;

	va_start(ap, format);
	res = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (res);
}
