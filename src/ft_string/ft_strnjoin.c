/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:53:46 by alamit            #+#    #+#             */
/*   Updated: 2019/03/27 22:53:48 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_string.h>

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char	*res;
	size_t	s1_len;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = s1 ? ft_strlen(s1) : 0;
	res = (char *)malloc((s1_len + n + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (s1)
		ft_strcpy(res, s1);
	ft_memcpy(res + s1_len, s2, n);
	res[s1_len + n] = '\0';
	return (res);
}
