/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memccpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:03:02 by alamit            #+#    #+#             */
/*   Updated: 2018/11/12 15:40:32 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <test42f.h>

void	test_ft_memccpy(void)
{
	printf("%sTesting ft_memccpy%s\n", KCYN, KNRM);

	char	dst1[10];
	char	dst2[10];
	char 	src1[] = "abcdef";
	char	src2[] = "abcdef";

	memset(dst1, 0, 10);
	memset(dst2, 0, 10);
	test42f_str_eq("Return values with char in string",
					ft_memccpy(dst1, src1, 'd', 7),
					memccpy(dst2, src2, 'd', 7));
	test42f_str_eq("Strings after ccpy with char in string",
					dst1, dst2);
	bzero(dst1, 10);
	bzero(dst2, 10);
	test42f_ptr_eq("Return values, char not in string",
					ft_memccpy(dst1, src1, '@', 7),
					memccpy(dst2, src2, '@', 7));
	test42f_str_eq("Strings after, char not in string",
					dst1,
					dst2);
}
