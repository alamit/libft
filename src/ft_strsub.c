/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:33:22 by alamit            #+#    #+#             */
/*   Updated: 2018/11/14 00:02:40 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if (start >= len)
		return (ft_strnew(0));
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
