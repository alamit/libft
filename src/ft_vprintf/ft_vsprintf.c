/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:57:54 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:59:39 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>

int		ft_vsprintf(char **str, const char *format, va_list ap)
{
	return (ft_modvprintf(-1, str, format, ap));
}
