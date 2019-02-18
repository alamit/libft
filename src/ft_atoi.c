/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:49:33 by alamit            #+#    #+#             */
/*   Updated: 2019/02/18 19:38:18 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		sign;
	int		res;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		++str;
		sign = -1;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0') * sign;
		++str;
	}
	return (res);
}
