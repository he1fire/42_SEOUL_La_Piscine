/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:24:51 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 17:34:12 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>
#	include <stdlib.h>
#	include "bsq.h"

void	print_square(char **map, t_info *info, t_xy xy)
{
	int i;
	int j;

	i = xy.x;
	while (i > xy.x - xy.len)
	{
		j = xy.y;
		while (j > xy.y - xy.len)
		{
			map[i][j] = info->full;
			j--;
		}
		i--;
	}
	i = 0;
	while (i < info->row)
	{
		write(1, map[i], info->col);
		write(1, "\n", 1);
		i++;
	}
}

void	fill_arr(char **map, int **arr, t_info *info)
{
	int		i;
	int		j;
	t_xy	xy;

	xy.len = -1;
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			if (arr[i][j] == 1 && i > 0 && j > 0)
				arr[i][j] = min(arr, i, j) + 1;
			if (arr[i][j] > xy.len)
			{
				xy.len = arr[i][j];
				xy.x = i;
				xy.y = j;
			}
			j++;
		}
		i++;
	}
	print_square(map, info, xy);
}

void	solve_square(char **map, t_info *info)
{
	int i;
	int j;
	int **arr;

	arr = (int **)malloc(sizeof(int *) * info->row);
	i = 0;
	while (i < info->row)
	{
		j = 0;
		arr[i] = (int *)malloc(sizeof(int) * info->col);
		while (j < info->col)
		{
			if (map[i][j] == info->obs)
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
			j++;
		}
		i++;
	}
	fill_arr(map, arr, info);
	i = 0;
	while (i < info->row)
		free(arr[i++]);
	free(arr);
}

int		main(int argc, char *argv[])
{
	t_info	info;
	int		i;

	if (argc == 1)
		std_input(&info);
	i = 1;
	while (i < argc)
	{
		if (file_input(&info, argv[i]) == 0)
			write(1, "map error\n", 10);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
