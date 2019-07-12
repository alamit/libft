/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:53:28 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:57:42 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>
#include <stdio.h>

int		ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(stdout, format, ap));
}
