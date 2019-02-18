/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:57:10 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 22:16:30 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	s1_len;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	res = (char *)malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + s1_len, s2);
	return (res);
}
