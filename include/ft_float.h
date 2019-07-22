/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:01:23 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:24:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <inttypes.h>
# include <ft_bigint.h>
# include <ft_floattypes.h>

# define INVALEXP 0xFFFF
# define F80_MAXDIGITS_B10 11494
# define F80_MAXDEC_B10 11494
# define F80_MAXFRAC_B10 11494

/*
**	Union to extract fields from a long double.
**	The long double should be a 80-bit extended precision
**	as specified by the IEE-754 standard.
*/
typedef union		u_ldext
{
	t_float80	n;
	struct
	{
		uint64_t	mantissa;
		uint16_t	exp : 15;
		uint8_t		sign : 1;
	}			f;
}					t_ldext;

typedef enum		e_f80_type
{
	VAL, INF, NAN
}					t_f80_type;

typedef struct		s_f80_data
{
	t_f80_type	type;
	uint8_t		sign;
	int16_t		expb2;
	uint64_t	mantissa;
}					t_f80_data;

typedef struct		s_f80_b10
{
	uint8_t		sign;
	char		decimal[F80_MAXDEC_B10];
	char		fractional[F80_MAXFRAC_B10];
	int16_t		exp;
	uint8_t		sci;
	size_t		precision;
	uint8_t		carry;
	size_t		dec_len;
	size_t		frac_len;
	uint8_t		nan;
	uint8_t		inf;
}					t_f80_b10;

t_f80_data			ft_float80_extract(t_float80 n);
void				ft_float80_b10(t_f80_b10 *b10, t_float80 n, size_t pre,
	uint8_t sci);

#endif
