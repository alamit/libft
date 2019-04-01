/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_params.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:35:49 by alamit            #+#    #+#             */
/*   Updated: 2019/03/27 18:41:35 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_PARAMS_H
# define FT_FLOAT_PARAMS_H

typedef struct	s_float_params
{
	const char	*low_nan;
	const char	*low_inf;
	const char	*up_nan;
	const char	*up_inf;
}				t_float_params;

t_float_params	*ft_float_params(void);
const char		*ft_float_params_inf(int up);
const char		*ft_float_params_nan(int up);

#endif
