/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 06:42:46 by alamit            #+#    #+#             */
/*   Updated: 2019/07/03 18:32:02 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_conv.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>

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
	long double		n = -1.0;
	long double		m = 9999999999999999989.0L;
	long double		o = 99999.999999999999L;
	(void)n;
	(void)o;
	t_ldext			ext;
	ext.n = m;
	setlocale(LC_ALL, "");
	struct lconv *ptrLocale = localeconv();
	ptrLocale->thousands_sep = "'";
	ptrLocale->decimal_point = ".";
	//ext.f.mantissa >>= 63;
	ext.f.exp -= 16180;
	// ext.f.exp = 0; // DENORMAL
	// char	buf[15000];
	// int		expb10 = ft_ld2buf(buf, ext.n, 10, 0);
	// printf("%se%+d\n\n", buf, expb10);
	// printf("%+50.10Le\n", ext.n);
	// fflush(stdout);
	t_buff	buf;
	ft_buff_init(&buf, 1, NULL);
	ft_conv_f(&buf, "%+50.20000Le", ext.n);
	ft_debuff(&buf);
	printf("\n%+50.20000Lf\n", ext.n);
	// int x = ft_conv_f(&buff, "%+0200.10Lf", ext.n);
	// ft_debuff(&buff);
	// puts("");
	// printf("%d\n", x);
	return (0);
}
