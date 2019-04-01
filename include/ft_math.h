/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:07:18 by alamit            #+#    #+#             */
/*   Updated: 2019/03/28 14:12:50 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <inttypes.h>
# include <sys/types.h>

unsigned int	ft_isqrt(unsigned int n);
unsigned int	ft_lowersqrt(unsigned int n);
int				ft_ipow(int n, unsigned int exp);
int				ft_isprime(unsigned int n);
uint64_t		ft_abs(int64_t n);
size_t			ft_log10(uint64_t n);

#endif
