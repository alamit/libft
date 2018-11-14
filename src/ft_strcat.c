/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:16:31 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 22:18:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dst, const char *src)
{
	char	*res;

	res = dst;
	dst += ft_strlen(dst);
	ft_strcpy(dst, src);
	return (res);
}
