/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:34:48 by alamit            #+#    #+#             */
/*   Updated: 2019/04/04 07:55:55 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <sys/types.h>
# include <ft_floattypes.h>
# include <ft_format.h>

/*
**	Convertsions from string to type.
*/
int				ft_atoi(const char *str);

/*
**	Conversions from types to buffer.
*/
size_t			ft_conv_e(char *buf, const char *format, t_float80 n);
int				ft_conv_f(char *buf, const char *format, t_float80 n);
int				ft_conv_d(char *buf, const char *format, int64_t n);
int				ft_fconv(char *buf, t_format *format, t_float80 n);
char			*ft_itoa_buf(char *buf, size_t size, int n);

/*
**	Conversions from types to dynamically allocated string.
*/
char			*ft_itoa(int n);

#endif
