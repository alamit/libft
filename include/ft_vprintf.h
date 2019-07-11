/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:41:07 by alamit            #+#    #+#             */
/*   Updated: 2019/02/27 15:53:02 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_H
# define FT_VPRINTF_H

# include <stdarg.h>
# include <ft_format.h>

int		ft_vsprintf(char **str, const char *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vprintf(const char *format, va_list ap);
int		ft_modvprintf(int fd, char **str, const char *format, va_list ap);

int		ft_write_signed(t_format *f, t_buff *buff, va_list ap);
int		ft_write_unsigned(t_format *f, t_buff *buff, va_list ap);
int		ft_write_float(t_format *f, t_buff *buff, va_list ap);
int		ft_write_char(t_format *f, t_buff *buff, va_list ap);

#endif
