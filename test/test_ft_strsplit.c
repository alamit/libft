/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:15:04 by alamit            #+#    #+#             */
/*   Updated: 2018/11/19 13:03:12 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <libft.h>

void	test_ft_strsplit(void)
{
	printf("%sTesting ft_strsplit.%s\n", KCYN, KNRM);

	char	str[] = "abc abc abc";
	char	*exp[] = {"abc", "abc", "abc", NULL};

	test42f_strarr_eq("Test 1",
						ft_strsplit(str, ' '),
						exp);

	char	str1[] = "abc    ";
	char	*exp1[] = {"abc", NULL};

	test42f_strarr_eq("Test 2",
						ft_strsplit(str1, ' '),
						exp1);

	char	str2[] = "         ";
	char	*exp2[] = {NULL};

	test42f_ptr_eq("Test 3",
						ft_strsplit(str2, ' ')[0],
						exp2[0]);
}
