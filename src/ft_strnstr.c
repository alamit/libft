/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:33:03 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 15:05:00 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[i] && i < len)
			++i;
		if (needle[i] == '\0')
			return ((char *)haystack);
		++haystack;
		len--;
	}
	return (NULL);
}
