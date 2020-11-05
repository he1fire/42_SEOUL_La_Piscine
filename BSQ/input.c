/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 04:23:29 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/04 04:27:25 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"

void	std_input_fill_map(char **map, t_info *info, char *tmp)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < info->row)
	{
		len = read(1, tmp, 100000);
		tmp[len] = 0;
		map[i] = (char *)malloc(sizeof(char) * len);
		j = 0;
		while (j < len - 1)
		{
			map[i][j] = tmp[j];
			j++;
		}
		map[i][j] = 0;
		i++;
	}
	map[i] = 0;
}

void	std_input(t_info *info)
{
	char	**map;
	char	tmp[100000];
	int		len;

	len = read(1, tmp, 100000);
	tmp[len] = 0;
	if (chk_info(tmp, info) == 0)
	{
		write(1, "map error\n\n", 11);
		return ;
	}
	map = (char **)malloc(sizeof(char *) * (info->row + 1));
	std_input_fill_map(map, info, tmp);
	if (chk_map(map, info) == 0)
		write(1, "map error\n", 10);
	else
		solve_square(map, info);
	len = 0;
	while (len < info->row)
		free(map[len++]);
	write(1, "\n", 1);
	free(map);
}

void	file_input_fill_map(char **map, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*str != '\n')
		str++;
	str++;
	while (*str != 0)
	{
		tmp = str;
		while (*str != 0 && *str != '\n')
			str++;
		map[i] = (char *)malloc(str - tmp + 1);
		str_copy(map[i], tmp, str);
		i++;
		str++;
	}
	map[i] = 0;
}

char	*file_input_str(t_info *info, char *argv)
{
	char	*ret;
	int		cnt;
	int		len;
	char	tmp[100000];

	if (open(argv, O_RDONLY) == -1)
		return (0);
	len = 0;
	while ((cnt = read(3, tmp, 100000)) != 0)
		len += cnt;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	close(3);
	open(argv, O_RDONLY);
	read(3, ret, len);
	ret[len] = 0;
	close(3);
	if (chk_info(ret, info) == 0)
	{
		free(ret);
		return (0);
	}
	return (ret);
}

int		file_input(t_info *info, char *argv)
{
	char	**map;
	char	*str;
	int		len;
	int		ret;

	ret = 1;
	str = file_input_str(info, argv);
	if (str == 0)
		return (0);
	map = (char **)malloc(sizeof(char *) * (find_set(str) + 1));
	file_input_fill_map(map, str);
	if (chk_map(map, info) == 0)
		ret = 0;
	else
		solve_square(map, info);
	len = 0;
	while (len < find_set(str) + 1)
		free(map[len++]);
	free(str);
	free(map);
	return (ret);
}
