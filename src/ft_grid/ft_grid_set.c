/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:55:13 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 18:01:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_grid.h>

int				ft_grid_set(t_grid *grid, size_t l, size_t c, char x)
{
	if (!grid || l >= grid->max_l || c >= grid->max_c)
		return (-1);
	grid->g[l][c] = x;
	return (0);
}
