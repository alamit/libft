/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:24:37 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:12:21 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (i + ft_strlen(src));
}
