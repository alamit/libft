/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:04:27 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:35:22 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_conv.h>

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

char			*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = numlen(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	return (ft_itoa_buf(res, len + 1, n));
}
