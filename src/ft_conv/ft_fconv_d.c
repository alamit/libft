/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:55:13 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:51:59 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_math.h>
#include <inttypes.h>
#include <ft_format.h>
#include <ft_ctype.h>

int		ft_fconv_d(t_buff *buf, t_format *f, int64_t n)
{
	uint64_t	un;

	if (ft_format_sign(f, n < 0))
		ft_buffc(buf, ft_format_sign(f, n < 0), 1);
	un = ft_abs(n);
	return (ft_fconv_u(buf, f, un));
}
