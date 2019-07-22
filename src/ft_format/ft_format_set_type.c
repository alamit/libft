/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_set_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:18:28 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 10:36:09 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_ctype.h>

void	ft_format_set_type(t_format *f, char type)
{
	if (type == 'p')
		ft_format_set_flag(f, '#');
	f->type = ft_isupper(type) ? ft_tolower(type) : type;
	if (type == 'D' || type == 'O' || type == 'U'
		|| type == 'I' || type == 'B' || type == 'p')
		ft_format_add_length_mod(f, 'l');
	else
		f->upper = ft_isupper(type);
}
