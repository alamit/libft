/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_params_nan.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:43:50 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 20:07:35 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_float_params.h>

const char	*ft_float_params_nan(int up)
{
	t_float_params	*fp;

	fp = ft_float_params();
	return (up ? fp->up_nan : fp->low_nan);
}
