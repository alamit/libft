/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:05:30 by alamit            #+#    #+#             */
/*   Updated: 2018/11/14 00:06:59 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <libft.h>

void	test_ft_strtrim(void)
{
	printf("%sTesting ft_strtrim.%s\n", KCYN, KNRM);

	test42f_str_eq("Check 1", ft_strtrim("   \t \n"), "");
}
