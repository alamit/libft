/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:04:56 by alamit            #+#    #+#             */
/*   Updated: 2019/09/21 17:27:56 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stack.h>
#include <ft_string.h>
#include <stdlib.h>

int		ft_stack_new(t_stack **sp, size_t max_len)
{
	if (!sp
		|| !(*sp = (t_stack *)malloc(sizeof(t_stack)))
		|| !((*sp)->elems = (int *)malloc(sizeof(int) * max_len)))
		return (-1);
	(*sp)->len = 0;
	(*sp)->bottom = max_len - 1;
	(*sp)->top = max_len;
	return (0);
}
