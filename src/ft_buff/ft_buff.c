/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:00:14 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 14:41:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_buff.h>
#include <ft_string.h>

int		ft_buff(t_buff *buff, const char *arr, size_t len)
{
	size_t	remaining;

	remaining = BUFF_SIZE - buff->idx;
	if (len < remaining)
	{
		ft_memcpy(buff->buffer + buff->idx, arr, len);
		buff->idx += len;
		return (1);
	}
	ft_memcpy(buff->buffer + buff->idx, arr, remaining);
	buff->idx += remaining;
	if (!ft_debuff(buff))
		return (0);
	return (ft_buff(buff, arr + remaining, len - remaining));
}
