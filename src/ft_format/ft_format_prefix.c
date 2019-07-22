/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:57 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 10:36:50 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

const char	*ft_format_prefix(t_format *f, size_t len)
{
	if (ft_format_has_flag(f, '#'))
	{
		if ((f->type == 'x' && len) || f->type == 'p')
			return (f->upper ? "0X" : "0x");
		else if (f->type == 'o')
			return (f->precision > len ? "" : "0");
		else if (f->type == 'b' && len)
			return (f->upper ? "0B" : "0b");
	}
	return ("");
}
