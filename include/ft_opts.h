/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:36:57 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 18:32:27 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTS_H
# define FT_OPTS_H

# include <inttypes.h>

typedef uint64_t	t_opts;

int					ft_opts_toggle(t_opts *opts, char flag);
int					ft_opts_parse(t_opts *opts, int *ac, char **av,
									const char *valid);
int					ft_opts_on(t_opts *opts, char flag);

#endif
