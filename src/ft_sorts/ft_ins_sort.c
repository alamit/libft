/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 08:20:40 by alamit            #+#    #+#             */
/*   Updated: 2019/09/20 08:27:36 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	ft_ins_sort(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (++i < len)
	{
		tmp = arr[i];
		j = i - 1;
		while (j < len && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}
