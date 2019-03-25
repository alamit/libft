/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:34:48 by alamit            #+#    #+#             */
/*   Updated: 2019/03/25 15:14:29 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <sys/types.h>
# include <inttypes.h>

/*
**	Union to extract fields from a long double.
**	The long double should be a 80-bit extended precision
**	as specified by the IEE-754 standard.
*/
typedef union	u_ldext
{
	long double	n;
	struct
	{
		uint64_t	mantissa;
		uint16_t	exp : 15;
		uint8_t		sign : 1;
	}			f;
}				t_ldext;

/*
**	Convertsions from string to type.
*/
int				ft_atoi(const char *str);

/*
**	Conversions from types to buffer.
*/
void			ft_ld2buf(char *buf, long double n);
char			*ft_itoa_buf(char *buf, size_t size, int n);

/*
**	Conversions from types to dynamically allocated string.
*/
char			*ft_itoa(int n);

#endif
