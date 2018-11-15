/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:04:27 by alamit            #+#    #+#             */
/*   Updated: 2018/11/14 21:30:52 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	numlen(int n)
{
	size_t	res;

	res = 0;
	if (n <= 0)
		++res;
	while (n)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	int		sign;

	len = numlen(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	res[0] = '0';
	sign = (n < 0) ? -1 : 1;
	while (n)
	{
		res[--len] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		res[--len] = '-';
	return (res);
}
