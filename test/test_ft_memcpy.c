/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:03:02 by alamit            #+#    #+#             */
/*   Updated: 2018/11/12 15:41:05 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <test42f.h>

void	test_ft_memcpy(void)
{
	printf("%sTesting ft_memcpy%s\n", KCYN, KNRM);

	int		dst1[] = {1, 2, 3};
	int		src1[] = {5, 6, 7};
	int		dst2[] = {1, 2 ,3};
	int 	src2[] = {5, 6 ,7};
	test42f_intarr_eq("ft_memcpy 4 bytes of int array works fine",
						3,
						ft_memcpy(dst1, src1, sizeof(int)),
						memcpy(dst2, src2, sizeof(int)));
}
