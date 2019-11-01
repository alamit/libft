/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:47:48 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:33:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_grid.h>
#include <ft_string.h>

int		ft_grid_clear(t_grid *grid)
{
	size_t	i;

	if (!grid)
		return (-1);
	i = 0;
	while (i < grid->max_l)
	{
		ft_memset(grid->g[i], ' ', grid->max_c);
		grid->g[i][grid->max_c] = '\0';
		++i;
	}
	return (0);
}
