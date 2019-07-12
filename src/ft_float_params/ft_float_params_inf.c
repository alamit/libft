/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_params_inf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:42:07 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 19:48:27 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_float_params.h>

const char	*ft_float_params_inf(int up)
{
	t_float_params	*fp;

	fp = ft_float_params();
	return (up ? fp->up_inf : fp->low_inf);
}
