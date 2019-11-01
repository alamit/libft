/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 07:56:13 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:41:38 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORTS_H
# define FT_SORTS_H

# include <sys/types.h>

typedef enum	e_order
{
	ASCENDING, DESCENDING
}				t_order;

void			ft_ins_sort(int *arr, size_t len);
int				ft_is_sorted(int *arr, size_t len, t_order order);
size_t			ft_indexof(int *sorted, int elem);

#endif
