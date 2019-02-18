/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:38:08 by alamit            #+#    #+#             */
/*   Updated: 2018/11/23 17:13:56 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_isqrt(unsigned int n)
{
	unsigned int	res;

	res = 0;
	while (res * res <= n && res < (1 << 16) - 1)
		res++;
	return (res - 1);
}