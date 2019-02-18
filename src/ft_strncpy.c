/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:03:10 by alamit            #+#    #+#             */
/*   Updated: 2019/02/18 19:42:04 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

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
