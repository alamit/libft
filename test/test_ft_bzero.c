/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:50:58 by alamit            #+#    #+#             */
/*   Updated: 2018/11/12 10:56:55 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <ft.h>

void	test_ft_bzero(void)
{
	printf("%sTesting ft_bzero%s\n", KCYN, KNRM);

	int t1[] = {1, 1, 1, 1};
	int	exp1[] = {0, 1, 1, 1};
	ft_bzero(t1, sizeof(int));
	test42f_intarr_eq("Change four bytes of int array sets 1st elem to 0",
						4,
						t1,
						exp1);
}
