/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:30:59 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 14:42:05 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <test42f.h>

void	test_ft_strstr(void)
{
	printf("%sTesting ft_strstr.%s\n", KCYN, KNRM);

	char *s1 = "FF";
	char *s2 = "see FF your FF return FF now FF";
	char *i1 = strstr(s1, s2);
	char *i2 = ft_strstr(s1, s2);

	test42f_ptr_eq("Basic test",
					i2,
					i1);//strstr(haystack, needle));
	printf("%s\n", i2);
}
