/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:37:52 by alamit            #+#    #+#             */
/*   Updated: 2019/04/01 11:58:33 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFF_H
# define FT_BUFF_H

# include <sys/types.h>

# define BUFF_SIZE 2048

typedef struct	s_buff
{
	char	buffer[BUFF_SIZE];
	size_t	idx;
	int		fd;
	char	**strp;
	size_t	written;
}				t_buff;

void			ft_buff_init(t_buff *buff, int fd, char **strp);
int				ft_buff(t_buff *buff, const char *arr, size_t len);
int				ft_buffs(t_buff *buff, const char *str);
int				ft_buffc(t_buff *buff, char c, size_t n);
int				ft_debuff(t_buff *buff);

#endif
