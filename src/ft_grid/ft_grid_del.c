/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:04:14 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:25:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_grid.h>
#include <stdlib.h>

void			ft_grid_del(t_grid **grid)
{
	size_t	i;

	if (!grid || !*grid)
		return ;
	i = -1;
	while (++i < (*grid)->max_l)
		free((*grid)->g[i]);
	free((*grid)->g);
	free(*grid);
	*grid = NULL;
}
