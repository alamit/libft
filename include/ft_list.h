/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:29:09 by alamit            #+#    #+#             */
/*   Updated: 2019/03/21 03:27:32 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <sys/types.h>

typedef struct	s_list {
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
size_t			ft_lstlen(t_list *lst);
t_list			*ft_lststrsplit(const char *s, char c);
t_list			*ft_lstfoldleft(t_list *lst,
								t_list *zero,
								t_list *(*op)(t_list *, t_list *));
void			**ft_lst_to_array(t_list *lst);

#endif
