/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:21:50 by alamit            #+#    #+#             */
/*   Updated: 2019/01/24 15:37:49 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

/*
**  Function to delete a string used by ft_lstdel.
**  The (void) trick is necessary to silence compilation error, because of the
**  design asked by the libft specification. The content_size should not be
**  needed to free memory (free knows how much to free thanks to malloc).
**  See ft_lstnew.
*/

static void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

/*
**  Adds a buffer to the queue, if the head of the queue is non NULL,
**  the first line of the buffer will be concanetated to it.
**
**  Returns -1 on ERROR, and 0 on SUCCESS.
*/

static int	add_buff_to_queue(t_list **queue, char *buffer)
{
	t_list	*split;
	char	*tmp;

	split = ft_lststrsplit(buffer, '\n');
	if (split == NULL)
		return (-1);
	tmp = split->content;
	split->content = ft_strjoin(*queue ? (*queue)->content : NULL, tmp);
	free(tmp);
	ft_lstdelone(queue, del);
	*queue = split;
	if ((*queue)->content == NULL)
		return (-1);
	return (0);
}

/*
**  Updates the queue when necessary, if the queue only has one
**  element, it means it is a unfinished line, so we neeed to read
**  more from file. If the queue has multiple elements, it it does nothing.
**
**  Returns 1 : Continue reading, file or queue is not empty.
**  Returns 0 : Stop reading, nothing left in either file or queue.
**  Return -1 : Error when reading or allocating memory
**
**  NOTE: If the last element in the queue is an empty string and nothing is
**  left in the file, we should ignore this last element, the empty string is
**  used to separate newlines in the queue when the buffer ends with a newline,
**  e.g. BUFF_SIZE = 1.
*/

static int	update_queue(const int fd, t_list **queues)
{
	ssize_t	read_bytes;
	char	buffer[BUFF_SIZE + 1];

	if (queues[fd] == NULL || queues[fd]->next == NULL)
	{
		while ((read_bytes = read(fd, buffer, BUFF_SIZE)))
		{
			if (read_bytes == -1)
				return (-1);
			buffer[read_bytes] = '\0';
			if (add_buff_to_queue(queues + fd, buffer))
				return (-1);
			if (queues[fd]->next)
				return (1);
		}
		if (queues[fd] == NULL ||
			(*(char *)queues[fd]->content == '\0' && queues[fd]->next == NULL))
			return (0);
		else
			return (1);
		return (queues[fd] == NULL ? 0 : 1);
	}
	return (1);
}

/*
**  Stores a line from a file in the line pointer to string.
**  A queue is used to store the remaining string(s) from the buffer.
**
**  Return 1 : There is still stuff to read from file or queue.
**  Return 0 : There is nothing left to read.
**  Return -1 : ERROR reading or allocating memory.
*/

int			get_next_line(const int fd, char **line)
{
	static t_list	*queues[MAX_FD];
	t_list			*tmp;
	int				res;

	if (line == NULL || fd < 0 || fd >= MAX_FD)
		return (-1);
	res = update_queue(fd, queues);
	if (res <= 0)
	{
		*line = NULL;
		ft_lstdel(queues + fd, del);
		return (res);
	}
	tmp = queues[fd];
	*line = tmp->content;
	queues[fd] = queues[fd]->next;
	ft_lstdelone(&tmp, NULL);
	return (res);
}
