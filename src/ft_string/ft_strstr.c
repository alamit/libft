/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 00:09:16 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 22:15:12 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[i])
			++i;
		if (needle[i] == '\0')
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
