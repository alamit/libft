/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:43:28 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:32:09 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <sys/types.h>

typedef struct	s_stack
{
	int			*elems;
	size_t		len;
	size_t		bottom;
	size_t		top;

}				t_stack;

int				ft_stack_get(const t_stack *s, size_t i);
int				ft_stack_new(t_stack **sp, size_t max_len);
int				ft_stack_push(t_stack *s, int elem);
int				ft_stack_pop(t_stack *s);
int				ft_stack_swap_first(t_stack *s);
int				ft_stack_rotate_up(t_stack *s);
int				ft_stack_rotate_down(t_stack *s);
void			ft_stack_del(t_stack **s);

#endif
