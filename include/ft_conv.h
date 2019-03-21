/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:34:48 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:34:47 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <sys/types.h>

/*
**	Convertsions from string to type.
*/
int				ft_atoi(const char *str);

/*
**	Conversions from types to buffer.
*/
char			*ft_itoa_buf(char *buf, size_t size, int n);

/*
**	Conversions frpm types to dynamically allocated string.
*/
char			*ft_itoa(int n);

#endif
