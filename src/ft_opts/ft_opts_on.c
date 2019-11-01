/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_on.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:59:45 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 17:23:57 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_opts.h>
#include <ft_ctype.h>

int		ft_opts_on(t_opts *opts, char flag)
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
	return (*opts & 0x1 << shift);
}
