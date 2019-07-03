/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:07:18 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 18:30:44 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <inttypes.h>
# include <sys/types.h>

unsigned int	ft_isqrt(unsigned int n);
unsigned int	ft_lowersqrt(unsigned int n);
int64_t			ft_ipow(int64_t n, uint8_t exp);
int				ft_isprime(unsigned int n);
uint64_t		ft_abs(int64_t n);
size_t			ft_log10(uint64_t n);
uint64_t		ft_submin0(uint64_t a, uint64_t b);
uint64_t		ft_max(uint64_t a, uint64_t b);
uint64_t		ft_min(uint64_t a, uint64_t b);

#endif
