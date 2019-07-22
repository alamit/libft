/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:19:09 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:40:28 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_buff.h>
#include <stddef.h>

void	ft_buff_init(t_buff *buff, int fd, char **strp)
{
	buff->idx = 0;
	buff->fd = fd;
	if (strp)
		*strp = NULL;
	buff->strp = strp;
	buff->written = 0;
}
