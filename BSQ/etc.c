/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:36:36 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 04:37:16 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	str_copy(char *str, char *st, char *ed)
{
	while (st < ed)
	{
		*str = *st;
		st++;
		str++;
	}
	*str = 0;
}

int		find_set(char *str)
{
	int ret;

	ret = 0;
	while (*str != '\n')
		str++;
	str++;
	while (*str != 0)
	{
		ret++;
		while (*str != 0 && *str != '\n')
			str++;
		str++;
	}
	return (ret);
}

int		min(int **arr, int x, int y)
{
	int a;
	int b;
	int c;

	a = arr[x - 1][y - 1];
	b = arr[x - 1][y];
	c = arr[x][y - 1];
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else
		return (c);
}
