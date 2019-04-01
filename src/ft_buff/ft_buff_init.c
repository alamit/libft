/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:19:09 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 21:25:09 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_buff.h>
#include <stddef.h>

void	ft_buff_init(t_buff *buff, int fd, char **strp)
{
	buff->idx = 0;
	buff->fd = fd;
	buff->strp = strp;
	buff->written = 0;
}
