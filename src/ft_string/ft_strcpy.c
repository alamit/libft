/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:55:25 by alamit            #+#    #+#             */
/*   Updated: 2018/11/28 10:03:26 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*res;

	res = dst;
	while (*src)
	{
		*dst = *src;
		++src;
		++dst;
	}
	*dst = '\0';
	return (res);
}
