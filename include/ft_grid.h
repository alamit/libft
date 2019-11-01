/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:40:33 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 16:17:16 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRID_H
# define FT_GRID_H

# include <sys/types.h>

typedef struct	s_grid
{
	char	**g;
	size_t	max_l;
	size_t	max_c;
}				t_grid;

int				ft_grid_new(t_grid **gri, size_t l, size_t c);
int				ft_grid_clear(t_grid *grid);
int				ft_grid_set(t_grid *grid, size_t l, size_t c, char x);
int				ft_grid_fill_col(t_grid *grid, size_t c, char x);
char			*ft_grid_getline(t_grid *grid, size_t c);
void			ft_grid_del(t_grid **grid);

#endif
