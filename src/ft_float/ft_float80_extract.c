/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float80_extract.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:05:10 by alamit            #+#    #+#             */
/*   Updated: 2019/07/17 07:14:38 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_float.h>

#define MIN_EXP -16382

t_f80_data	ft_float80_extract(t_float80 n)
{
	t_ldext		extractor;
	t_f80_data	res;

	extractor.n = n;
	res.sign = extractor.f.sign;
	if (extractor.f.exp >= 0x7FFF)
	{
		if (!(extractor.f.mantissa << 1))
			res.type = INF;
		else
			res.type = NAN;
		res.expb2 = 0;
		res.mantissa = 0;
		res.sign = res.type == NAN ? 0 : res.sign;
		return (res);
	}
	res.type = VAL;
	res.expb2 = !extractor.f.exp && extractor.f.mantissa
		? MIN_EXP : MIN_EXP + extractor.f.exp - 1;
	if (!extractor.f.exp && !extractor.f.mantissa)
		res.expb2 = 0;
	res.mantissa = extractor.f.mantissa;
	return (res);
}
