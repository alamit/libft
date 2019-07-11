/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:55:13 by alamit            #+#    #+#             */
/*   Updated: 2019/07/04 09:30:26 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <inttypes.h>
#include <ft_format.h>
#include <ft_math.h>

int		ft_fconv_d(t_buff *buf, t_format *f, int64_t n)
{
	return (ft_fconv_integer(buf, f, ft_abs(n), n < 0));
}
