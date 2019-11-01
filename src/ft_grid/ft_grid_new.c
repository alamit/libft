/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:45:30 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:20:49 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_grid.h>
#include <stdlib.h>

int		ft_grid_new(t_grid **grid, size_t l, size_t c)
{
	size_t	i;

	i = -1;
	if (!grid || !(*grid = (t_grid *)malloc(sizeof(t_grid)))
		|| !((*grid)->g = (char **)malloc((l + 1) * sizeof(char *))))
		return (-1);
	while (++i < l)
		if (!((*grid)->g[i] = (char *)malloc((c + 1) * sizeof(char))))
			return (-1);
	(*grid)->g[i] = 0;
	(*grid)->max_c = c;
	(*grid)->max_l = l;
	return (0);
}
