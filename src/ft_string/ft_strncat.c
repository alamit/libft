/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:19:41 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:13:23 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*res;

	res = dst;
	dst += ft_strlen(dst);
	while (*src && n)
	{
		*dst = *src;
		src++;
		dst++;
		n--;
	}
	*dst = '\0';
	return (res);
}
