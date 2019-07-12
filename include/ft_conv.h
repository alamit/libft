/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:34:48 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 10:31:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <sys/types.h>
# include <ft_floattypes.h>
# include <ft_format.h>
# include <ft_buff.h>
# include <stdarg.h>

/*
**	Convertsions from string to type.
*/
int				ft_atoi(const char *str);

/*
**	Conversions from types to buffer.
*/

int				ft_fconv_e(t_buff *buf, t_format *format, t_float80 n);
int				ft_fconv_f(t_buff *buf, t_format *format, t_float80 n);
int				ft_fconv_d(t_buff *buf, t_format *format, int64_t n);
int				ft_fconv_u(t_buff *buf, t_format *format, uint64_t n);
int				ft_fconv_x(t_buff *buf, t_format *format, uint64_t n);
int				ft_fconv_o(t_buff *buf, t_format *format, uint64_t n);
int				ft_fconv_b(t_buff *buf, t_format *format, uint64_t n);
int				ft_fconv_c(t_buff *buf, t_format *format, int c);
int				ft_fconv_s(t_buff *buf, t_format *format, char *s);
int				ft_fconv_integer(t_buff *buf, t_format *format, uint64_t n,
					uint8_t sign);
int				ft_fconv_u_base(t_buff *buf, t_format *format, uint64_t n,
					uint8_t base_expb2);

int				ft_vfconv_e(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_f(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_d(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_u(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_x(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_o(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_b(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_c(t_buff *buf, t_format *f, va_list ap);
int				ft_vfconv_s(t_buff *buf, t_format *f, va_list ap);

int				ft_conv_e(t_buff *buf, const char *format, t_float80 n);
int				ft_conv_f(t_buff *buf, const char *format, t_float80 n);
int				ft_conv_d(t_buff *buf, const char *format, int64_t n);
int				ft_conv_u(t_buff *buf, const char *format, uint64_t n);
int				ft_conv_x(t_buff *buf, const char *format, uint64_t n);
int				ft_conv_o(t_buff *buf, const char *format, uint64_t n);
int				ft_conv_b(t_buff *buf, const char *format, uint64_t n);
int				ft_conv_c(t_buff *buf, const char *format, int c);
int				ft_conv_s(t_buff *buf, const char *format, char *s);

char			*ft_itoa_buf(char *buf, size_t size, int n);

/*
**	Conversions from types to dynamically allocated string.
*/
char			*ft_itoa(int n);

#endif
