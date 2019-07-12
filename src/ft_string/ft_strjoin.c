/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:57:10 by alamit            #+#    #+#             */
/*   Updated: 2019/03/27 22:55:26 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	if (s2 == NULL)
		return (ft_strnjoin(s1, NULL, 0));
	return (ft_strnjoin(s1, s2, ft_strlen(s2)));
}
