/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opts_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:11:27 by alamit            #+#    #+#             */
/*   Updated: 2019/10/14 17:27:11 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_opts.h>
#include <ft_string.h>
#include <ft_ctype.h>

int		ft_opts_parse(t_opts *opts, int *ac, char **av, const char *valid)
{
	size_t	i;
	size_t	j;

	if (!opts || !ac || !av || !valid)
		return (-1);
	i = 1;
	*opts = 0;
	while (i < (size_t)*ac)
	{
		j = 0;
		if (av[i][0] == '-' && !av[i][1])
			return (-1);
		while (++j && av[i][0] == '-' && av[i][j])
			if (ft_strchr(valid, av[i][j]) && ft_opts_toggle(opts, av[i][j]))
				return (-1);
			else if (ft_isdigit(av[i][j]))
				break ;
			else if (!ft_strchr(valid, av[i][j]))
				return (-1);
		if (j > 1)
			ft_memmove(av + i, av + i + 1, ((*ac)-- - i) * sizeof(char *));
		i += (j == 1);
	}
	return (0);
}
