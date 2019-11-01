/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:07:05 by alamit            #+#    #+#             */
/*   Updated: 2019/09/20 08:16:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <stdlib.h>
#include <ft_string.h>

int		ft_stack_push(t_stack *s, int elem)
{
	if (!s || !s->top)
		return (-1);
	s->top--;
	s->elems[s->top] = elem;
	s->len++;
	return (0);
}
