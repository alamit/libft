/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 05:01:10 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 09:16:47 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGINT_H
# define FT_BIGINT_H

# include <sys/types.h>
# include <stdint.h>
/*
**	This value should not be less than 516 to maintain IEE-754 extended
**	representation accurate.
**	abs(-16384 - 63 -63) / sizeof(unsigned)
**
*/
# define BI_MAX_SIZE 516

typedef struct	s_bigint
{
	size_t		size;
	uint32_t	arr[BI_MAX_SIZE];
}				t_bigint;

t_bigint		ft_bigint_new(uint64_t n);
int				ft_bigint_cmp(const t_bigint *a, const t_bigint *b);
void			ft_bigint_add(t_bigint *dst, const t_bigint *src);
void			ft_bigint_addu(t_bigint *dst, uint32_t n);
void			ft_bigint_sub(t_bigint *dst, const t_bigint *src);
void			ft_bigint_lshift(t_bigint *dst, size_t n);
void			ft_bigint_rshift(t_bigint *dst, size_t n);
void			ft_bigint_mulpow10(t_bigint *bi, size_t n);
uint32_t		ft_bigint_div(t_bigint *mod, const t_bigint *div, uint32_t q_max);
uint32_t		ft_bigint_divpow10(t_bigint *mod, size_t pow, u_int32_t q_max);

#endif
