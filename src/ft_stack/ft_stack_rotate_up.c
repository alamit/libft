/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:57:48 by alamit            #+#    #+#             */
/*   Updated: 2019/09/19 21:24:09 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <ft_string.h>

int		ft_stack_rotate_up(t_stack *s)
{
	int		tmp;

	if (!s)
		return (-1);
	if (s->len < 2)
		return (0);
	tmp = s->elems[s->top];
	ft_memmove(s->elems + s->top,
		s->elems + s->top + 1,
		(s->len - 1) * sizeof(int));
	s->elems[s->bottom] = tmp;
	return (0);
}
