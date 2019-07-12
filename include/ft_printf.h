/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:21:09 by alamit            #+#    #+#             */
/*   Updated: 2019/02/26 15:39:02 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_sprintf(char **str, const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
