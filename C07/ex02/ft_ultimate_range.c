/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:29:47 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/27 22:33:47 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *arr;
	int i;

	arr = 0;
	if (min >= max)
	{
		*range = arr;
		return (0);
	}
	arr = (int *)malloc((max - min) * sizeof(int));
	if (arr == 0)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (max - min);
}
