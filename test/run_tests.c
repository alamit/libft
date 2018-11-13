/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:47:14 by alamit            #+#    #+#             */
/*   Updated: 2018/11/12 18:22:13 by alamit           ###   ########.fr       */
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
	return (0);
}
