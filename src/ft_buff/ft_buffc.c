/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:13:12 by alamit            #+#    #+#             */
/*   Updated: 2019/02/28 10:26:04 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_buff.h>

int		ft_buffc(t_buff *buff, char c, size_t n)
{
	int		res;

	res = 1;
	while (n--)
	{
		res = res && ft_buff(buff, &c, 1);
		if (!res)
			return (res);
	}
	return (res);
}
