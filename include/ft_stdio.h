/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:24:03 by alamit            #+#    #+#             */
/*   Updated: 2019/03/20 20:30:52 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# define BUFF_SIZE 10000

/*
**		Important notes:
**		MAX_FD is an OS limit, fds are limited to 10240 on OSX by
**		kern.maxfilesperproc. (I think linux is 65536).
**		Should be reading RLIMIT_NOFILE for portabiity.
**		Even better, a static Hashmap would be better suited, fd is allowed
**		by POSIX to be INT_MAX and the stack would not be able to handle it.
*/
# define MAX_FD 10240

void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putendl(const char *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		get_next_line(const int fd, char **line);

#endif
