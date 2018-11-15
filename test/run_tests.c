/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:47:14 by alamit            #+#    #+#             */
/*   Updated: 2018/11/14 21:16:08 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

int		main(void)
{
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memccpy();
	test_ft_memcmp();
	test_ft_strlcat();
	test_ft_strstr();
	test_ft_atoi();
	test_ft_strtrim();
	test_ft_strsplit();
	test_ft_itoa();
	return (0);
}
