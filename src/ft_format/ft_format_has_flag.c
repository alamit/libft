/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_has_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:07:23 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 14:55:24 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_string.h>

int8_t		ft_format_has_flag(t_format *f, char flag)
{
	if (flag == '#')
		return (f->flags & 0x01);
	else if (flag == '0')
		return (f->flags & 0x02);
	else if (flag == ' ')
		return (f->flags & 0x04);
	else if (flag == '+')
		return (f->flags & 0x08);
	else if (flag == '-')
		return (f->flags & 0x10);
	else
		return (0);
}
