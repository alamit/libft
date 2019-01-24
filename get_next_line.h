/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:21:53 by alamit            #+#    #+#             */
/*   Updated: 2019/01/24 15:36:17 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000
# define MAX_FD 10240

/*
**		Important notes:
**		MAX_FD is an OS limit, fds are limited to 10240 on OSX by
**		kern.maxfilesperproc. (I think linux is 65536).
**		Should be reading RLIMIT_NOFILE for portabiity.
**		Even better, a static Hashmap would be better suited, fd is allowed
**		by POSIX to be INT_MAX and the stack would not be able to handle it.
*/

#endif
