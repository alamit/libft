/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:42:57 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:33:52 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_conv.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	out[12];

	ft_putstr_fd(ft_itoa_buf(out, 12, n), fd);
}
