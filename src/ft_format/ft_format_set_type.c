/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_set_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:18:28 by alamit            #+#    #+#             */
/*   Updated: 2019/07/11 18:44:02 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_ctype.h>

void	ft_format_set_type(t_format *f, char type)
{
	if (type == 'p')
	{
		f->type = 'x';
		ft_format_add_length_mod(f, 'l');
	}
	else
		f->type = ft_tolower(type);
	if (type == 'X' || type == 'D' || type == 'O' || type == 'U' || type == 'C'
		|| type == 'S' || type =='B')
		ft_format_add_length_mod(f, 'l');
	else
		f->upper = ft_isupper(type);
}
