/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:36:53 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 10:22:31 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_ctype.h>
#include <ft_string.h>
#include <stddef.h>

#define FLAGS "#0 +-'"
#define LEN_MOD "hlLz"
#define TYPES "diouxXDOUfFeEcCsSpbB%"

static int	is_flag(char c)
{
	return (ft_strchr(FLAGS, c) != NULL);
}

static int	is_len_mod(char c)
{
	return (ft_strchr(LEN_MOD, c) != NULL);
}

static int	is_type(char c)
{
	return (ft_strchr(TYPES, c) != NULL);
}

static int	format_valid(t_format *f)
{
	if (f->type == 'e' || f->type == 'f' || f->type =='E' || f->type == 'F'
		|| f->type == 'c' || f->type =='s')
		return (f->length_mod == 0  || f->length_mod == 1);
	if (f->type == 'd' || f-> type == 'i' || f->type == 'o' || f->type == 'u'
		|| f->type == 'x' || f->type == 'b')
		return (f->length_mod >= -2 && f->length_mod <= 2);
	return (0);
}

ssize_t		ft_format_parse(t_format *f, const char *format)
{
	const char *start;

	start = format;
	ft_bzero(f, sizeof(t_format));
	if (!(*format == '%') || !*++format)
		return (-1);
	while (is_flag(*format))
		ft_format_set_flag(f, *(format++));
	f->field_width = ft_atoi(format);
	while (ft_isdigit(*format))
		++format;
	f->precision = *format == '.' ? ft_atoi(++format) : 6;
	while (ft_isdigit(*format))
		++format;
	while (is_len_mod(*format))
		ft_format_add_length_mod(f, *(format++));
	if (is_type(*format))
		ft_format_set_type(f, *(format++));
	else
		return (-1);
	return (format_valid(f) ? format - start : -1);
}
