/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:03:08 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 20:05:22 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_buff.h>

int		ft_buffs(t_buff *buff, const char *str)
{
	while (*str)
	{
		if (!ft_buff(buff, str, 1))
			return (0);
		str++;
	}
	return (1);
}