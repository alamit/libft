/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:49:11 by alamit            #+#    #+#             */
/*   Updated: 2019/09/19 21:25:31 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <stddef.h>

int		ft_stack_swap_first(t_stack *s)
{
	int	tmp;

	if (!s)
		return (-1);
	if (s->len < 2)
		return (0);
	tmp = s->elems[s->top];
	s->elems[s->top] = s->elems[s->top + 1];
	s->elems[s->top + 1] = tmp;
	return (0);
}
