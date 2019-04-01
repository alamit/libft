/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:34:48 by alamit            #+#    #+#             */
/*   Updated: 2019/03/27 22:46:17 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <sys/types.h>
# include <ft_floattypes.h>
# include <ft_format.h>
# include <ft_buff.h>

/*
**	Convertsions from string to type.
*/
int				ft_atoi(const char *str);

/*
**	Conversions from types to buffer.
*/
int				ft_conv_e(t_buff *buff, const char *format, t_float80 n);
int				ft_conv_d(t_buff *buff, const char *format, int64_t n);
int				ft_fconv(t_buff *buff, t_format *format, t_float80 n);
char			*ft_itoa_buf(char *buf, size_t size, int n);

/*
**	Conversions from types to dynamically allocated string.
*/
char			*ft_itoa(int n);

#endif
