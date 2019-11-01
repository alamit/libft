/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:09:28 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:36:44 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>
#include <ft_string.h>

static int	strcmpnum(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	return (l1 != l2 ? l1 < l2 : s1[l1 - 1] <= s2[l2 - 1]);
}

int			ft_isint(const char *s)
{
	size_t	i;

	if (!s || !(ft_isdigit(*s) || *s == '-' || *s == '+'))
		return (0);
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	if (ft_isdigit(*s))
		return (strcmpnum(s, "2147483647"));
	else if (*s == '-')
		return (strcmpnum(s, "-2147483648"));
	else
		return (strcmpnum(s, "+2147483647"));
}
