/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:13:37 by alamit            #+#    #+#             */
/*   Updated: 2018/11/14 21:23:07 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test42f.h>
#include <libft.h>

void	test_ft_itoa(void)
{
	printf("%sTestting ft_itoa.%s\n", KCYN, KNRM);

	test42f_str_eq("INT MIN", ft_itoa(-2147483648), "-2147483648");
	test42f_str_eq("-623", ft_itoa(-623), "-623");
	test42f_str_eq("-156", ft_itoa(-156), "-156");
	test42f_str_eq("-0", ft_itoa(-0), "0");
}
