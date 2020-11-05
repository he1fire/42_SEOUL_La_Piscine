/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:12:26 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 21:34:58 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <fcntl.h>
#	include <unistd.h>
#	include <stdlib.h>
#	include "use_str.h"

int		chk_dict(char **dict)
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = 0;
	while (dict[i] != 0)
	{
		j = 0;
		while ('0' <= dict[i][j] && dict[i][j] <= '9')
			j++;
		if (j > ret)
			ret = j;
		while (dict[i][j] == ' ')
			j++;
		if (dict[i][j] != ':')
			return (-9999);
		i++;
	}
	return (ret);
}

int		chk_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		i++;
	}
	return (1);
}

void	fill_dict(char **dict, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*str != 0)
	{
		if (*str != '\n')
		{
			tmp = str;
			while (*str != 0 && *str != '\n')
				str++;
			dict[i] = (char *)malloc(str - tmp + 1);
			str_copy(dict[i], tmp, str);
			i++;
		}
		str++;
	}
	dict[i] = 0;
}

int		chk_error(int argc, char *argv[], int *fd)
{
	if (argc == 2)
		*fd = open("numbers.dict", O_RDONLY);
	else if (argc == 3)
		*fd = open(argv[1], O_RDONLY);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (chk_num(argv[argc - 1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int		chk_dict_error(char **dict, char *str, int argc, char *argv[])
{
	if (dict == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	fill_dict(dict, str);
	if (chk_dict(dict) + 2 < str_len(argv[argc - 1]))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}
