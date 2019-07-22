/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:24:55 by alamit            #+#    #+#             */
/*   Updated: 2019/07/22 13:25:08 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include <sys/types.h>
# include <inttypes.h>
# include <ft_buff.h>
# include <stdarg.h>

typedef struct	s_format
{
	uint8_t		flags;
	uint32_t	field_width;
	uint32_t	precision;
	int8_t		length_mod;
	char		type;
	uint8_t		upper;
}				t_format;

const char		*ft_format_parse(t_format *f, const char *format);
void			ft_format_set_flag(t_format *f, char flag);
void			ft_format_add_length_mod(t_format *f, char length_mod);
void			ft_format_set_type(t_format *f, char type);
void			ft_format_set_precision(t_format *f, int32_t precision);

int8_t			ft_format_has_flag(t_format *f, char flag);
size_t			ft_format_left_padding(t_format *f, size_t conv_len, char sign,
	const char *prefix);
char			ft_format_sign(t_format *f, int is_neg);
const char		*ft_format_prefix(t_format *f, size_t len);
size_t			ft_format_zero_padding(t_format *f, size_t len, char sign,
	const char *prefix);
char			ft_format_separator(t_format *f);
size_t			ft_format_precision(t_format *f);
size_t			ft_format_right_padding(t_format *f, size_t len, char sign,
	const char *prefix);
int8_t			ft_format_lenmod(t_format *f);
char			ft_format_type(t_format *f);

int				ft_format_write(t_buff *buf, t_format *f, va_list ap);

#endif
