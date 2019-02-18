/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:19:41 by alamit            #+#    #+#             */
/*   Updated: 2019/02/18 19:41:56 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

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
