/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:25:19 by alamit            #+#    #+#             */
/*   Updated: 2019/02/18 19:42:40 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

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
