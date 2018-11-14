/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:25:41 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 21:32:36 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 == s2)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}
