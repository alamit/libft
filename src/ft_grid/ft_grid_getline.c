/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_getline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:17:29 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 18:01:01 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_grid.h>
#include <stddef.h>

char			*ft_grid_getline(t_grid *grid, size_t l)
{
	if (!grid || l >= grid->max_l)
		return (NULL);
	return (grid->g[l]);
}
