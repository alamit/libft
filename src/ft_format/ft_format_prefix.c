/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:24:57 by alamit            #+#    #+#             */
/*   Updated: 2019/07/04 16:28:54 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

const char	*ft_format_prefix(t_format *f)
{
	if (ft_format_has_flag(f, '#'))
	{
		if (f->type == 'x')
			return (f->upper ? "0X" : "0x");
		else if (f->type == 'o')
			return ("0");
		else if (f->type == 'b')
			return (f->upper ? "0B" : "0b");
	}
	return ("");
}
