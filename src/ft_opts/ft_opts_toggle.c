/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_toggle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:44:03 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 16:21:08 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_opts.h>
#include <ft_ctype.h>

int		ft_opts_toggle(t_opts *opts, char flag)
{
	uint8_t	shift;

	if (!opts)
		return (-1);
	if (ft_isdigit(flag))
		shift = ft_char2num(flag);
	else if (ft_islower(flag))
		shift = 10 + flag - 'a';
	else if (ft_isupper(flag))
		shift = 36 + flag - 'A';
	else
		return (-1);
	*opts ^= 0x1 << shift;
	return (0);
}
