/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:56:09 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:57:30 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>
#include <stddef.h>

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	return (ft_modvprintf(fd, NULL, format, ap));
}
