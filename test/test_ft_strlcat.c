/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:03 by alamit            #+#    #+#             */
/*   Updated: 2018/11/19 12:13:48 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <libft.h>

void	test_ft_strlcat(void)
{
	printf("%sTesting ft_strlcat.%s\n", KCYN, KNRM);

	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

	test42f_int_eq("check 1",
					ft_strlcat(buff1, str, max),
					strlcat(buff2, str, max));
	test42f_str_eq("check 2", buff1, buff2);

	char s1[4] = "";
	char s2[4] = "";
	test42f_int_eq("check 3",
					ft_strlcat(s1, "thx to ntoniolo for this test !", 4),
					strlcat(s2, "thx to ntoniolo for this test !", 4));
	test42f_int_eq("check 4",
					ft_strlcat(buff1, str, 0),
					strlcat(buff1, str, 0));

	char	*dest;
	char	*dest1;
	dest = ft_memalloc(15);
	dest1 = ft_memalloc(15);
	memset(dest, 'r', 6);
	memset(dest1, 'r', 6);
	dest[11] = 'a';
	dest1[11] = 'a';
	test42f_int_eq("check 5", ft_strlcat(dest, "lorem", 15), strlcat(dest1, "lorem", 15));
	test42f_str_eq("check 6", dest, dest1);
}
