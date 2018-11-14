/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:30:44 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 14:08:32 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <test42f.h>

void	test_ft_memcmp(void)
{
	printf("%sTesting ft_memcmp.%s\n", KCYN, KNRM);

	test42f_int_eq("Comparing more bytes than strlen",
					ft_memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4),
					memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4));
	test42f_int_eq("Comparing with n == 0",
					ft_memcmp("bdshjkvfads", "asdfdsavc", 0),
					memcmp("bdshjkvfads", "asdfdsavc", 0));
}
