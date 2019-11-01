/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_fill_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:02:14 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 18:00:34 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_grid.h>

int				ft_grid_fill_col(t_grid *grid, size_t c, char x)
{
	size_t	i;

	if (!grid || c >= grid->max_l)
		return (-1);
	i = 0;
	while (i < grid->max_c)
	{
		grid->g[i][c] = x;
		++i;
	}
	return (0);
}
