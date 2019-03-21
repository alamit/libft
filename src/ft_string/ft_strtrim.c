/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:25:19 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:37:55 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

static int	weird_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(const char *s)
{
	unsigned int	start;
	size_t			len;

	if (s == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (weird_isspace(s[start]))
	{
		++start;
		--len;
	}
	while (len && weird_isspace(s[start + len - 1]))
		--len;
	return (ft_strsub(s, start, len));
}
