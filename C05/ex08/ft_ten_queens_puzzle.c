/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:18:43 by mchoe             #+#    #+#             */
/*   Updated: 2020/10/25 09:24:22 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>

void	fill_cell(int (*arr)[10], int x, int y, int value)
{
	int i;

	i = -9;
	while (i < 10)
	{
		if (i != 0)
		{
			if (0 <= x + i && x + i < 10)
				arr[x + i][y] += value;
			if (0 <= y + i && y + i < 10)
				arr[x][y + i] += value;
			if (0 <= x + i && x + i < 10 && 0 <= y + i && y + i < 10)
				arr[x + i][y + i] += value;
			if (0 <= x - i && x - i < 10 && 0 <= y + i && y + i < 10)
				arr[x - i][y + i] += value;
		}
		i++;
	}
}

int		solve_puzzle(int (*arr)[10], char *str, int depth)
{
	int i;
	int ret;

	ret = 0;
	if (depth == 10)
	{
		write(1, str, 10);
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (arr[depth][i] == 0)
		{
			str[depth] = i + '0';
			fill_cell(arr, depth, i, 1);
			ret += solve_puzzle(arr, str, depth + 1);
			fill_cell(arr, depth, i, -1);
		}
		i++;
	}
	return (ret);
}

int		ft_ten_queens_puzzle(void)
{
	int		arr[10][10];
	char	str[10];
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (solve_puzzle(arr, str, 0));
}
