/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:44:31 by alamit            #+#    #+#             */
/*   Updated: 2018/11/12 15:41:16 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <libft.h>

void	test_ft_memset(void)
{
	printf("%sTesting ft_memset%s\n", KCYN, KNRM);

	char	*str = strdup("Hello");
	ft_memset(str, 0x40, 5);
	test42f_str_eq("Changes characters", str, "@@@@@");

	int		arr[] = {1, 2, 3, 4, 5};
	int		exp[] = {168430090, 168430090, 168430090, 168430090, 168430090};
	ft_memset(arr, 10, 5 * sizeof(int));
	test42f_intarr_eq("Changes array of ints", 5, arr, exp);

	test42f_str_eq("Same behavior when going further array",
		ft_memset(arr, 1, 10),
		memset(arr, 1, 10));
}
