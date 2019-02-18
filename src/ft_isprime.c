/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:19:52 by alamit            #+#    #+#             */
/*   Updated: 2019/02/18 19:38:51 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isprime(unsigned int n)
{
	unsigned int i;
	unsigned int max_div;

	if (n < 2)
		return (0);
	else if (n % 2 == 0)
		return (1);
	i = 3;
	max_div = ft_isqrt(n) + 1;
	while (i <= max_div)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
