/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:00:28 by alamit            #+#    #+#             */
/*   Updated: 2019/07/04 17:02:31 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <inttypes.h>

size_t	ft_log(uint64_t n, uint8_t base)
{
	size_t	res;

	res = 0;
	while (n > 0)
	{
		n /= base;
		++res;
	}
	return (res);
}
