/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:25:13 by alamit            #+#    #+#             */
/*   Updated: 2019/07/04 16:41:25 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_string.h>

char	ft_format_sign(t_format *f, int is_neg)
{
	if (is_neg)
		return ('-');
	else if (ft_strchr("dife", f->type) && ft_format_has_flag(f, '+'))
		return ('+');
	else if (ft_strchr("dife", f->type) && ft_format_has_flag(f, ' '))
		return (' ');
	return ('\0');
}
