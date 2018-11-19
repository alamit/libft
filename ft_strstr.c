/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 00:09:16 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 14:54:56 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
