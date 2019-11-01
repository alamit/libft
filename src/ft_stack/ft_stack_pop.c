/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:43:46 by alamit            #+#    #+#             */
/*   Updated: 2019/09/19 21:28:49 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <stdlib.h>
#include <ft_string.h>

int		ft_stack_pop(t_stack *s)
{
	if (!s || !s->len)
		return (-1);
	s->len--;
	s->top++;
	return (0);
}
