/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modvprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:07:55 by alamit            #+#    #+#             */
/*   Updated: 2019/07/12 11:22:25 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vprintf.h>
#include <ft_buff.h>
#include <ft_format.h>
#include <stdlib.h>

static int	is_anchor(char c)
{
	return (c == '%');
}

static int	convert(const char *format, t_buff *buff, va_list ap)
{
	t_format	f;
	int			res;

	if (!ft_format_parse(&f, format))
		return (0);
	if ((res = ft_format_write(buff, &f, ap)) < 0)
		return (0);
	return (1);
}

int			ft_modvprintf(int fd, char **str, const char *format, va_list ap)
{
	t_buff		buff;

	ft_buff_init(&buff, fd, str);
	while (*format)
	{
		if (is_anchor(*format))
		{
			if (!convert(format, &buff, ap))
				return (-1);
			continue;
		}
		if (!ft_buff(&buff, format, 1))
			return (-1);
		format++;
	}
	if (!ft_debuff(&buff))
		return (-1);
	return (buff.written);
}
