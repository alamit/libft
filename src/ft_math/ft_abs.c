/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:53:48 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 14:13:39 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>

uint64_t	ft_abs(int64_t n)
{
	if (n < 0)
		return ((uint64_t)-n);
	return ((uint64_t)n);
}
