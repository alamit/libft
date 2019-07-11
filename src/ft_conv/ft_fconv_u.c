/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fconv_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:57:39 by alamit            #+#    #+#             */
/*   Updated: 2019/07/04 09:30:21 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <inttypes.h>
#include <ft_format.h>

int				ft_fconv_u(t_buff *buf, t_format *f, uint64_t n)
{
	return (ft_fconv_integer(buf, f, n, 0));
}
