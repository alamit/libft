/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_add_length_mod.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:55:58 by alamit            #+#    #+#             */
/*   Updated: 2019/07/02 16:06:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>

void		ft_format_add_length_mod(t_format *f, char length_mod)
{
	if (length_mod == 'l' && (f->length_mod == 0 || f->length_mod == 1)
		f->length_mod++;
	else if (length_mod == 'h' && (f->length_mod == 0 || f->length_mod == -1))
		f->length_mod--;
	else if (length_mod == 'L' && f->length_mod == 0)
		f->length_mod++;
	else if (length_mod == 'z' && f->length_mod == 0)
		f->length_mod += 2;
}
