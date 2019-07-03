/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_u_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:58:08 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:01:49 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_math.h>
#include <inttypes.h>
#include <ft_string.h>
#include <ft_format.h>
#include <ft_ctype.h>

int		ft_conv_u_base(t_buff *buf, t_format *f, uint64_t n, uint8_t base_expb2)
{
	size_t		len;
	size_t		i;

	len = ft_log10(n);
	i = 0;
	while (len || --f.precision)
		ft_buffc(buf, ft_num2char(n % (len ? --len : len) * 10), 1);
	(void)base_expb2;
	return (0);
}
