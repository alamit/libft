/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:26:55 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 11:28:38 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <ft_format.h>
#include <inttypes.h>

int		ft_fconv_x(t_buff *buf, t_format *f, uint64_t n)
{
	return (ft_fconv_u_base(buf, f, n, 4));
}
