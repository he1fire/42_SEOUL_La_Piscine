/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:30:01 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 04:32:33 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		simple_atoi(char *c, int size)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i <= size)
	{
		if (c[i] < '0' || '9' < c[i])
			return (-1);
		ret *= 10;
		ret += c[i] - '0';
		i++;
	}
	return (ret);
}

int		chk_info(char *tmp, t_info *info)
{
	int line;
	int i;

	i = 0;
	while (!(tmp[i] == '\n' || tmp[i] == '\0'))
		i++;
	if (i < 4)
		return (0);
	line = simple_atoi(tmp, i - 4);
	if (line < 1)
		return (0);
	info->empty = tmp[i - 3];
	info->obs = tmp[i - 2];
	info->full = tmp[i - 1];
	if (info->empty == info->obs || info->empty == info->full ||
		info->obs == info->full)
		return (0);
	info->row = line;
	info->col = -1;
	return (1);
}

int		chk_map(char **map, t_info *info)
{
	int obs_cnt;
	int i;
	int j;

	obs_cnt = 0;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] != info->empty && map[i][j] != info->obs)
				return (0);
			if (map[i][j] == info->obs)
				obs_cnt++;
			j++;
		}
		if (info->col != -1 && info->col != j)
			return (0);
		info->col = j;
		i++;
	}
	if (obs_cnt < 1 || info->row != i)
		return (0);
	return (1);
}
