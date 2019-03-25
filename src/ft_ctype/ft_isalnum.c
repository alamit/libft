/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:57:53 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 21:53:36 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}