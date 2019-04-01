/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:39:17 by alamit            #+#    #+#             */
/*   Updated: 2019/03/27 15:36:20 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_ctype.h>

static int	is_flag(char c)
{
	return (c == '#'
		|| c == '0'
		|| c == ' '
		|| c == '+'
		|| c == '-'
		|| c == '\'');
}

static int	is_len_mod(char c)
{
	return (c == 'h'
		|| c == 'l'
		|| c == 'L'
		|| c == 'z');
}

static int	is_type(char c)
{
	return (c == 'd' || c == 'D'
		|| c == 'i'
		|| c == 'o' || c == 'O'
		|| c == 'u' || c == 'U'
		|| c == 'x' || c == 'X'
		|| c == 'f' || c == 'F'
		|| c == 'e' || c == 'E'
		|| c == 'g' || c == 'G'
		|| c == 'c' || c == 'C'
		|| c == 's' || c == 'S'
		|| c == 'p'
		|| c == 'b'
		|| c == '%');
}

int			ft_format_parse(t_format *f, const char *format)
{
	size_t	i;

	i = -1;
	if (!*++format)
		return (0);
	while (++i < 6)
		f->flag[i] = is_flag(*format) ? *(format++) : 0;
	f->flag[6] = '\0';
	f->field_width = ft_atoi(format);
	while (ft_isdigit(*format))
		++format;
	f->precision = *format == '.' ? ft_atoi(++format) : -1;
	while (ft_isdigit(*format))
		++format;
	f->length_mod[0] = is_len_mod(*format) ? *(format++) : 0;
	f->length_mod[1] = is_len_mod(*format) ? *(format++) : 0;
	f->type = *(format++);
	if (!is_type(f->type))
		return (0);
	return (1);
}
