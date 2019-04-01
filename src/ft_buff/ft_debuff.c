/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:17:53 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 21:24:53 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_buff.h>
#include <unistd.h>
#include <ft_string.h>

int		ft_debuff(t_buff *buff)
{
	char	*tmp;

	if (buff->fd >= 0 && write(buff->fd, buff->buffer, buff->idx) < 0)
		return (0);
	else if (buff->strp)
	{
		tmp = *buff->strp;
		*buff->strp = ft_strnjoin(tmp, buff->buffer, buff->idx);
		ft_strdel(&tmp);
		if (*buff->strp == NULL)
			return (0);
	}
	buff->written += buff->idx;
	buff->idx = 0;
	return (1);
}
