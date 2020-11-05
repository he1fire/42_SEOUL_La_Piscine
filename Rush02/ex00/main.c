/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoe <mchoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:40:51 by mchoe             #+#    #+#             */
/*   Updated: 2020/11/01 18:30:30 by mchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <unistd.h>
#	include <stdlib.h>
#	include "chk_errors.h"
#	include "use_str.h"
#	include "print_num.h"

int		find_set(char *str)
{
	int ret;

	ret = 0;
	while (*str != 0)
	{
		if (*str != '\n')
		{
			ret++;
			while (*str != 0 && *str != '\n')
				str++;
		}
		str++;
	}
	return (ret);
}

void	recursive_str(char **dict, char *str, int depth, int max)
{
	int		len;
	int		i;
	int		cnt;
	char	tmp;

	len = str_len(str);
	if (len > 3)
	{
		tmp = str[len - 3];
		str[len - 3] = 0;
		recursive_str(dict, str, depth + 1, max);
		str[len - 3] = tmp;
	}
	i = -1;
	cnt = 0;
	while (++i < 3)
	{
		cnt *= 10;
		if (len - 3 + i >= 0)
			cnt += str[len - 3 + i] - '0';
	}
	if (depth + 1 < max && cnt != 0)
		write(1, " ", 1);
	print_hundred(dict, cnt, len);
	print_numerical_unit(dict, cnt, depth);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		len;
	char	tmp[10000];
	char	*str;
	char	**dict;

	if (chk_error(argc, argv, &fd) == 0)
		return (0);
	str = tmp;
	len = read(fd, tmp, 10000);
	tmp[len] = 0;
	dict = (char **)malloc(sizeof(char *) * (find_set(str) + 1));
	if (chk_dict_error(dict, str, argc, argv) == 0)
		return (0);
	recursive_str(dict, argv[argc - 1], 0, (str_len(argv[argc - 1]) + 2) / 3);
	write(1, "\n", 1);
	len = 0;
	while (len < find_set(str) + 1)
	{
		free(dict[len]);
		len++;
	}
	free(dict);
	close(fd);
	return (0);
}
