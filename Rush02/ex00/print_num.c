/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:27:40 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 18:29:27 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>
#	include <stdlib.h>
#	include "use_str.h"

void	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0 && str[i] == ' ')
		i++;
	i++;
	while (str[i] != 0 && str[i] == ' ')
		i++;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		find_str(char **dict, char *str)
{
	int len;
	int i;
	int j;

	i = -1;
	len = str_len(str);
	while (dict[++i] != 0)
	{
		j = 0;
		while (str[j] != 0 && dict[i][j] == str[j])
			j++;
		if (j == len && (dict[i][j] == ' ' || dict[i][j] == ':'))
		{
			print_str(&dict[i][j]);
			return (1);
		}
	}
	return (0);
}

void	print_ten(char **dict, int num, int cnt)
{
	char a[3];

	a[0] = num / 10 + '0';
	a[1] = num % 10 + '0';
	a[2] = 0;
	if (cnt == 1 && num != 0)
		write(1, " ", 1);
	if (num >= 10)
	{
		if (find_str(dict, a) == 0)
		{
			a[1] = '0';
			find_str(dict, a);
			a[1] = num % 10 + '0';
			write(1, " ", 1);
			find_str(dict, &a[1]);
		}
	}
	else if (!(cnt == 1 && num == 0))
		find_str(dict, &a[1]);
}

void	print_hundred(char **dict, int num, int zero)
{
	char	a[2];
	int		cnt;

	if (num == 0 && zero != 1)
		return ;
	cnt = 0;
	if (num >= 100)
	{
		a[0] = num / 100 + '0';
		a[1] = 0;
		find_str(dict, a);
		write(1, " hundred", 8);
		num %= 100;
		cnt = 1;
	}
	print_ten(dict, num, cnt);
}

void	print_numerical_unit(char **dict, int cnt, int depth)
{
	char	*unit;
	int		i;

	if (depth > 0 && cnt != 0)
	{
		write(1, " ", 1);
		unit = (char *)malloc(sizeof(char) * (depth * 3 + 2));
		unit[0] = '1';
		i = 1;
		while (i < depth * 3 + 1)
		{
			unit[i] = '0';
			i++;
		}
		unit[i] = 0;
		find_str(dict, unit);
		free(unit);
	}
}
