/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:48:08 by alamit            #+#    #+#             */
/*   Updated: 2018/11/21 16:07:06 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
void	a(char *c)
{
	*c = '@';
}

int		main(void)
{
	char s[] = "Un jour je serai, le meilleur dresseur !";
	printf("%s\n", ft_strsub(s, 8, 8));
}
