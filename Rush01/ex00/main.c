/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:04:18 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/28 16:04:07 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>
#	include "chk.h"

int g_chk[4][4];
/*
 **co_lup, col_down, row_left, row_right
*/
int g_arr[4][4];
int g_cnt_col[4][4];
int g_cnt_row[4][4];

int	print_arr(void)
{
	char	c;
	int		i;
	int		j;

	if (chk_up(g_arr, g_chk[0]) == 1 && chk_down(g_arr, g_chk[1]) == 1 &&
		chk_left(g_arr, g_chk[2]) == 1 && chk_right(g_arr, g_chk[3]) == 1)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				c = g_arr[i][j] + '0';
				write(1, &c, 1);
				if (j < 3)
					write(1, " ", 1);
			}
			write(1, "\n", 1);
		}
		return (1);
	}
	return (0);
}

int	backtrack(int depth, int ret)
{
	int		i;

	if (ret > 0)
		return (ret);
	if (depth == 4 * 4)
	{
		if (print_arr() == 1)
			ret++;
		return (ret);
	}
	i = -1;
	while (++i < 4)
	{
		if (g_cnt_row[depth / 4][i] == 0 && g_cnt_col[depth % 4][i] == 0)
		{
			g_arr[depth / 4][depth % 4] = i + 1;
			g_cnt_row[depth / 4][i] = 1;
			g_cnt_col[depth % 4][i] = 1;
			ret += backtrack(depth + 1, ret);
			g_cnt_row[depth / 4][i] = 0;
			g_cnt_col[depth % 4][i] = 0;
		}
	}
	return (ret);
}

int	fill_chk(char *str)
{
	int i;
	int num;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i] != 0)
	{
		if (i != 0 && str[i - 1] != ' ' && str[i] != ' ')
			return (0);
		else if (str[i] == ' ')
		{
			if (num < 1 || 4 < num)
				return (0);
			g_chk[cnt / 4][cnt % 4] = num;
			num = 0;
			cnt++;
		}
		num = str[i] - '0';
		i++;
	}
	if (cnt != 4 * 4 - 1 || num < 1 || 4 < num)
		return (0);
	g_chk[cnt / 4][cnt % 4] = num;
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "Error\n", 6);
	else if (fill_chk(argv[1]) == 0)
		write(1, "Error\n", 6);
	else if (backtrack(0, 0) == 0)
		write(1, "Error\n", 6);
	return (0);
}
