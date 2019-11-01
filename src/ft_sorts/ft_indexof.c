/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:40:41 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:41:41 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

size_t	ft_indexof(int *sorted, int elem)
{
	size_t	res;

	res = 0;
	while (sorted[res] != elem)
		res++;
	return (res);
}
