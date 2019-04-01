/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:37:15 by alamit            #+#    #+#             */
/*   Updated: 2019/04/01 12:52:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_float_params.h>

t_float_params	*ft_float_params(void)
{
	static t_float_params fp = {"nan", "inf", "NAN", "INF"};

	return (&fp);
}
