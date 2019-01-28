/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowersqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 02:25:59 by alamit            #+#    #+#             */
/*   Updated: 2019/01/28 02:26:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_lowersqrt(unsigned int n)
{
	unsigned int	res;

	res = 0;
	while (res * res < n && res < (1 << 16) - 1)
		res++;
	return (res - 1);
}
