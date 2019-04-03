/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:42:46 by alamit            #+#    #+#             */
/*   Updated: 2019/04/01 20:50:35 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <ft_buff.h>
#include <stdio.h>
#include <locale.h>

typedef union	s_ldext
{
	long double	n;
	struct
	{
		unsigned long	mantissa;
		unsigned short	exp;
		unsigned char	sign;
	}			f;
}				t_ldext;

int		main(void)
{
	long double		n = -4534534354354.4534354354354;
	long double		m = 49999999999999999989.0L;
	(void)m;
	t_ldext			ext;
	ext.n = n;
	setlocale(LC_ALL, "");
	struct lconv *ptrLocale = localeconv();
	ptrLocale->thousands_sep = "'";
	ptrLocale->decimal_point = ".";
	//ext.f.mantissa >>= 63;
	//ext.f.exp -= 16382;
	// ext.f.exp = 0; // DENORMAL
	// char	buf[15000];
	// int		expb10 = ft_ld2buf(buf, ext.n, 10, 0);
	// printf("%se%+d\n\n", buf, expb10);
	printf("%+20.100Lf\n", ext.n);
	fflush(stdout);
	t_buff	buff;
	ft_buff_init(&buff, 1, NULL);
	// ft_conv_e(&buff, "%+20.5000Le", ext.n);
	// ft_debuff(&buff);
	// puts("");
	int x = ft_conv_f(&buff, "%+0200.10Lf", ext.n);
	ft_debuff(&buff);
	puts("");
	printf("%d\n", x);
	return (0);
}
