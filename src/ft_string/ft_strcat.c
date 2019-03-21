/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:16:31 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:08:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strcat(char *dst, const char *src)
{
	char	*res;

	res = dst;
	dst += ft_strlen(dst);
	ft_strcpy(dst, src);
	return (res);
}
