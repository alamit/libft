/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_set_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:16:27 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 12:47:53 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

void	ft_format_set_flag(t_format *f, char flag)
{
	if (flag == '#')
		f->flags |= 0x01;
	else if (flag == '0')
		f->flags |= 0x02;
	else if (flag == ' ')
		f->flags |= 0x04;
	else if (flag == '+')
		f->flags |= 0x08;
	else if (flag == '-')
		f->flags |= 0x10;
	else if (flag == '\'')
		f->flags |= 0x20;
}