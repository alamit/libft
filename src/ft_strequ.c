/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:23:44 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 21:32:08 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 == s2)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strcmp(s1, s2) == 0);
}
