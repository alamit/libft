/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:01:23 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 19:51:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <inttypes.h>
# include <ft_bigint.h>
# include <ft_floattypes.h>

# define INVALEXP 0xFFFF
# define F80_MAXDIGITS_B10 11494

/*
**	Union to extract fields from a long double.
**	The long double should be a 80-bit extended precision
**	as specified by the IEE-754 standard.
*/
typedef union		u_ldext
{
	t_float80		n;
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

typedef struct 		s_f80_b10
{
	char		buf[F80_MAXDIGITS_B10];
	t_bigint	p;
	t_bigint	q;
	int16_t		exp;
	uint8_t		sign;
	const char	*(*inf)(int);
	const char	*(*nan)(int);
	size_t		(*get_digits)(struct s_f80_b10 *, size_t);
}					t_f80_b10;

t_f80_data		ft_float80_extract(t_float80 n);
void			ft_float80_b10(t_f80_b10 *b10, t_float80 n);

#endif
