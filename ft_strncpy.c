/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:03:10 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 13:14:24 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*res;

	res = dst;
	while (*src && n)
	{
		*dst = *src;
		src++;
		dst++;
		n--;
	}
	ft_bzero(dst, n);
	return (res);
}
