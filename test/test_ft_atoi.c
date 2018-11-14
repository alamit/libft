/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:30:13 by alamit            #+#    #+#             */
/*   Updated: 2018/11/13 17:02:36 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <libft.h>

void	test_ft_atoi(void)
{
	printf("%sTesting ft_atoi.%s\n", KCYN, KNRM);

	test42f_int_eq("ft_atoi(-50)", ft_atoi("-50"), atoi("-50"));
	test42f_int_eq("ft_atoi(-99999999999999999999999999)",
					ft_atoi("-999999999999999999"),
					atoi("-999999999999999999"));
	test42f_int_eq("ft_atoi(-99999999999999999999999999)",
					ft_atoi("1999999999999999999"),
					atoi("1999999999999999999"));
}
