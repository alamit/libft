/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:43:58 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:33:44 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sorts.h>

static int	cmp(int a, int b, t_order order)
{
	if (order == ASCENDING)
		return (a < b);
	else if (order == DESCENDING)
		return (a > b);
	else
		return (0);
}

int			ft_is_sorted(int *arr, size_t len, t_order order)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (++i < len)
	{
		if (!cmp(arr[i - 1], arr[i], order))
			return (0);
	}
	return (1);
}
