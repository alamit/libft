/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:47:47 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:35:11 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_itoa_buf(char *buf, size_t size, int n)
{
	int		sign;

	if (buf == NULL)
		return (NULL);
	buf[--size] = '\0';
	sign = (n < 0) ? -1 : 1;
	while (n || !buf[size])
	{
		buf[--size] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		buf[--size] = '-';
	return (buf + size);
}
