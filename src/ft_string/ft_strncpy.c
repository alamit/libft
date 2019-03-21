/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:03:10 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:13:42 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

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
