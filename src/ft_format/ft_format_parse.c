/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:36:53 by alamit            #+#    #+#             */
/*   Updated: 2019/04/05 15:33:46 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_format.h>
#include <ft_conv.h>
#include <ft_ctype.h>
#include <ft_string.h>
#include <stddef.h>

#define FLAGS "#0 +-'"
#define LEN_MOD "hlLz"
#define TYPES "diouxXDOUfFeEcCsSpb%"

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

ssize_t		ft_format_parse(t_format *f, const char *format)
{
	const char *start;

	ft_bzero(f, sizeof(t_format));
	if (!format == '%' || !*++format)
		return (-1);
	while (is_flag(*format))
		ft_format_set_flag(f, format++);
	f->field_width = ft_atoi(format);
	while (ft_isdigit(*format))
		++format;
	f->precision = *format == '.' ? ft_atoi(++format) : -1;
	while (ft_isdigit(*format))
		++format;
	while (is_len_mod(*format))
		ft_format_add_length_mod(f, format++);
	if (is_type(*format))
		ft_format_set_type(f, format++);
	else
		return (-1);
	return (format - start);
}
