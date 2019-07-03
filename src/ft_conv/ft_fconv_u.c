/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:57:39 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 12:35:38 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_math.h>
#include <inttypes.h>
#include <ft_format.h>
#include <ft_ctype.h>

int		ft_fconv_u(t_buff *buf, t_format *f, uint64_t n)
{
	size_t		p10;
	size_t		i;

	p10 = ft_ipow(10, ft_log10(n) - 1);
	i = 0;
	while (i++ < f->precision || p10)
	{
		ft_buffc(buf, ft_num2char(n / p10), 1);
		n %= p10;
		p10 /= 10;
	}
	return (0);
}
