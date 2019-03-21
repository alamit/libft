/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 05:17:08 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 10:14:35 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bigint.h>
#include <ft_string.h>

t_bigint	ft_bigint_new(uint64_t n)
{
	t_bigint	res;
	size_t		i;

	ft_bzero(res.arr, sizeof(uint32_t) * BI_MAX_SIZE);
	i = 0;
	while (n)
	{
		res.arr[i++] = UINT32_MAX & n;
		n >>= 32;
	}
	res.size = i;
	return (res);
}
